#!/bin/bash

PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $1"; PASS=$((PASS + 1)); }
fail() { echo -e "${RED}[FAIL]${NC} $1"; FAIL=$((FAIL + 1)); }

cp data.csv /tmp/data.csv

cd $(dirname "$BTC") 2>/dev/null || true
BTC="./btc"

echo "========================================="
echo "         TESTS EX00 - BitcoinExchange"
echo "========================================="

# sin argumentos
out=$($BTC 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Sin argumentos -> Error"
else
    fail "Sin argumentos deberia dar Error"
fi

# archivo inexistente
out=$($BTC archivo_que_no_existe.txt 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Archivo inexistente -> Error"
else
    fail "Archivo inexistente deberia dar Error"
fi

# input normal
cat > /tmp/test_input.txt << 'EOF'
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
EOF
out=$($BTC /tmp/test_input.txt 2>&1)
if echo "$out" | grep -q "2011-01-03 => 3"; then
    pass "Input normal -> resultado correcto"
else
    fail "Input normal -> resultado incorrecto: $out"
fi

# numero negativo
cat > /tmp/test_neg.txt << 'EOF'
date | value
2012-01-11 | -1
EOF
out=$($BTC /tmp/test_neg.txt 2>&1)
if echo "$out" | grep -q "Error: not a positive number"; then
    pass "Numero negativo -> Error: not a positive number"
else
    fail "Numero negativo -> mensaje incorrecto: $out"
fi

# numero demasiado grande
cat > /tmp/test_big.txt << 'EOF'
date | value
2012-01-11 | 2147483648
EOF
out=$($BTC /tmp/test_big.txt 2>&1)
if echo "$out" | grep -q "Error: too large a number"; then
    pass "Numero muy grande -> Error: too large a number"
else
    fail "Numero muy grande -> mensaje incorrecto: $out"
fi

# fecha invalida
cat > /tmp/test_date.txt << 'EOF'
date | value
2001-42-42
EOF
out=$($BTC /tmp/test_date.txt 2>&1)
if echo "$out" | grep -q "Error: bad input"; then
    pass "Fecha invalida -> Error: bad input"
else
    fail "Fecha invalida -> mensaje incorrecto: $out"
fi

# fecha sin separador |
cat > /tmp/test_sep.txt << 'EOF'
date | value
2012-01-11 1
EOF
out=$($BTC /tmp/test_sep.txt 2>&1)
if echo "$out" | grep -q "Error: bad input"; then
    pass "Sin separador | -> Error: bad input"
else
    fail "Sin separador | -> mensaje incorrecto: $out"
fi

# fecha no existe en DB, usa la inferior
cat > /tmp/test_closest.txt << 'EOF'
date | value
2011-01-04 | 1
EOF
out=$($BTC /tmp/test_closest.txt 2>&1)
if echo "$out" | grep -q "2011-01-04 =>"; then
    pass "Fecha no en DB -> usa fecha inferior"
else
    fail "Fecha no en DB -> fallo: $out"
fi

# valor 0
cat > /tmp/test_zero.txt << 'EOF'
date | value
2012-01-11 | 0
EOF
out=$($BTC /tmp/test_zero.txt 2>&1)
if echo "$out" | grep -q "Error"; then
    pass "Valor 0 -> Error (no positivo)"
else
    fail "Valor 0 -> deberia dar Error: $out"
fi

# valor float valido
cat > /tmp/test_float.txt << 'EOF'
date | value
2011-01-03 | 1.2
EOF
out=$($BTC /tmp/test_float.txt 2>&1)
if echo "$out" | grep -q "1.2"; then
    pass "Valor float -> procesado correctamente"
else
    fail "Valor float -> fallo: $out"
fi

echo "========================================="
echo "PASSED: $PASS | FAILED: $FAIL"
echo "========================================="

rm -f /tmp/test_*.txt