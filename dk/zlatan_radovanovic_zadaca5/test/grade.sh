#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

DIRNAME=$(dirname $0)

TESTEXE="$1"
INPUT=$(printf "%s.in" "$2")
EXPECTED_OUTPUT=$(printf "%s.out" "$2")

SUCCESS=""
FAIL=""

for testfile in $(ls $DIRNAME | grep -v 'sh' | cut -d'.' -f1 | sort -u); do
  if $DIRNAME/testme.sh $TESTEXE $DIRNAME/$testfile > /dev/null; then
    SUCCESS+=" $testfile"
  else
    FAIL+=" $testfile"
  fi
done

printf "${GREEN}Tests that succedded:${NC}\n"
echo $SUCCESS
printf "${RED}Tests that failed:${NC}\n"
echo $FAIL

