#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

TESTEXE="$1"
INPUT=$(printf "%s.in" "$2")
EXPECTED_OUTPUT=$(printf "%s.out" "$2")
OUTPUT=$(mktemp)

echo Testing "${INPUT}"
echo Input: 
echo ~~~
cat "${INPUT}"
echo ~~~

"${TESTEXE}" <"${INPUT}" >"${OUTPUT}"

if diff -q "$EXPECTED_OUTPUT" $OUTPUT; then
    printf "${GREEN}OK${NC}\n"
    SUCCESS=0
else
    printf "${RED}FAIL${NC}\n"
    printf "Expected output:\n~~~\n"
    cat "$EXPECTED_OUTPUT"
    printf "~~~\nYour output:\n~~~\n"
    cat "${OUTPUT}"
    echo ~~~
    SUCCESS=1
fi

rm "$OUTPUT"
exit "$SUCCESS"
