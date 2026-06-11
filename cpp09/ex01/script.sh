#!/bin/bash

PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $1"; PASS=$((PASS + 1)); }
fail() { echo -e "${RED}[FAIL]${NC} $1"; FAIL=$((FAIL + 1)); }

RPN="./RPN"

echo "========================================="
echo "         TESTS EX01 - RPN"
echo "========================================="

# sin argumentos
out=$($RPN 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Sin argumentos -> Error"
else
    fail "Sin argumentos deberia dar Error"
fi

# ejemplos del subject
out=$($RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" 2>&1)
if [ "$out" = "42" ]; then
    pass "8 9 * 9 - 9 - 9 - 4 - 1 + = 42"
else
    fail "8 9 * 9 - 9 - 9 - 4 - 1 + esperaba 42, obtuvo: $out"
fi

out=$($RPN "7 7 * 7 -" 2>&1)
if [ "$out" = "42" ]; then
    pass "7 7 * 7 - = 42"
else
    fail "7 7 * 7 - esperaba 42, obtuvo: $out"
fi

out=$($RPN "1 2 * 2 / 2 * 2 4 - +" 2>&1)
if [ "$out" = "0" ]; then
    pass "1 2 * 2 / 2 * 2 4 - + = 0"
else
    fail "1 2 * 2 / 2 * 2 4 - + esperaba 0, obtuvo: $out"
fi

# parentesis -> Error
out=$($RPN "(1 + 1)" 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Parentesis -> Error"
else
    fail "Parentesis deberia dar Error: $out"
fi

# division por cero
out=$($RPN "1 0 /" 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Division por cero -> Error"
else
    fail "Division por cero deberia dar Error: $out"
fi

# operador sin suficientes numeros
out=$($RPN "+" 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Operador solo -> Error"
else
    fail "Operador solo deberia dar Error: $out"
fi

# token invalido
out=$($RPN "1 2 a +" 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Token invalido -> Error"
else
    fail "Token invalido deberia dar Error: $out"
fi

# dos numeros sin operador
out=$($RPN "1 2" 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Dos numeros sin operador -> Error"
else
    fail "Dos numeros sin operador deberia dar Error: $out"
fi

# resta con resultado negativo
out=$($RPN "1 9 -" 2>&1)
if [ "$out" = "-8" ]; then
    pass "1 9 - = -8"
else
    fail "1 9 - esperaba -8, obtuvo: $out"
fi

# operaciones basicas
out=$($RPN "3 4 +" 2>&1)
if [ "$out" = "7" ]; then
    pass "3 4 + = 7"
else
    fail "3 4 + esperaba 7, obtuvo: $out"
fi

out=$($RPN "9 3 /" 2>&1)
if [ "$out" = "3" ]; then
    pass "9 3 / = 3"
else
    fail "9 3 / esperaba 3, obtuvo: $out"
fi

echo "========================================="
echo "PASSED: $PASS | FAILED: $FAIL"
echo "========================================="