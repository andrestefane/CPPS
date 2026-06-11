#!/bin/bash

PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $1"; PASS=$((PASS + 1)); }
fail() { echo -e "${RED}[FAIL]${NC} $1"; FAIL=$((FAIL + 1)); }

PM="./PmergeMe"

# FIX 2+5: comparacion numerica y guarda de vacio
check_sorted() {
    [ -z "$1" ] && return 1
    echo "$1" | tr ' ' '\n' | awk '
    NR > 1 && $1+0 < prev+0 { exit 1 }
    { prev = $1 }
    END { exit 0 }
    '
}

get_after() {
    echo "$1" | awk -F'After:' '/After:/ {print $2}' | tr -s ' ' | xargs
}

echo "========================================="
echo "         TESTS EX02 - PmergeMe"
echo "========================================="

# sin argumentos
out=$($PM 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Sin argumentos -> Error"
else
    fail "Sin argumentos deberia dar Error"
fi

# numero negativo
out=$($PM -1 2 3 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Numero negativo -> Error"
else
    fail "Numero negativo deberia dar Error"
fi

# cero
out=$($PM 0 1 2 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Cero -> Error"
else
    fail "Cero deberia dar Error"
fi

# letra
out=$($PM 1 2 a 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Letra -> Error"
else
    fail "Letra deberia dar Error"  # FIX 3: mensaje corregido
fi

# duplicado simple
out=$($PM 1 2 2 3 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Duplicado simple -> Error"
else
    fail "Duplicado simple deberia dar Error"
fi

# duplicado no adyacente
out=$($PM 3 7 1 9 3 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Duplicado no adyacente -> Error"
else
    fail "Duplicado no adyacente deberia dar Error"
fi

# ejemplo subject
out=$($PM 3 5 9 7 4 2>&1)
if echo "$out" | grep -q "Before:" && echo "$out" | grep -q "After:"; then
    pass "Output tiene Before y After"
else
    fail "Falta Before o After"
fi

# verificar After ordenado (caso subject)
after=$(get_after "$out")
if check_sorted "$after"; then
    pass "Subject -> ordenado correctamente"
else
    fail "Subject -> no esta ordenado"
fi

# un elemento
out=$($PM 5 2>&1)
after=$(get_after "$out")
[ "$after" = "5" ] && pass "Un elemento" || fail "Un elemento fallo"

# dos elementos
out=$($PM 9 1 2>&1)
after=$(get_after "$out")
[ "$after" = "1 9" ] && pass "Dos elementos" || fail "Dos elementos fallo"

# ya ordenado - FIX 1: espacio antes de 2>&1
out=$($PM 1 2 3 4 5 2>&1)
after=$(get_after "$out")
if check_sorted "$after"; then
    pass "Ya ordenado"
else
    fail "Ya ordenado fallo"
fi

# invertido - FIX 1: espacio antes de 2>&1
out=$($PM 5 4 3 2 1 2>&1)
after=$(get_after "$out")
if check_sorted "$after"; then
    pass "Invertido"
else
    fail "Invertido fallo"
fi

# straggler
out=$($PM 5 3 1 4 2 6 7 2>&1)
after=$(get_after "$out")
if check_sorted "$after"; then
    pass "Straggler (7 elementos)"
else
    fail "Straggler fallo"
fi

# tiempos
if echo "$out" | grep -q "vector" && echo "$out" | grep -q "deque"; then
    pass "Muestra tiempos vector/deque"
else
    fail "No muestra tiempos"
fi

# 3000 elementos
input=$(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
out=$($PM $input 2>&1)
after=$(get_after "$out")
if [ -z "$after" ]; then
    fail "3000 elementos -> After vacio"
elif check_sorted "$after"; then
    pass "3000 elementos -> ordenado correctamente"
else
    fail "3000 elementos -> NO ordenado"
fi

echo "========================================="
echo "PASSED: $PASS | FAILED: $FAIL"
echo "========================================="