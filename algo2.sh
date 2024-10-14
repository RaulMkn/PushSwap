#!/usr/bin/env zsh
make;
ARG="a"; echo -n "\"$ARG\": " > output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="111a11"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="hello world"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="0 0"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-01 -001"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="111-1 2 -3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-3 -2 -2"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="\n"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-2147483649"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-2147483650"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="2147483648"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="8 008 12"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="10 -1 -2 -3 -4 -5 -6 90 99 10"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="1 +1 -1"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="3333-3333 1 4"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="111a111 -4 3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="111111 -4 3 03"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="2147483649"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="2147483647+1"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="0 1 2 3 4 5 0"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="3 +3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="3+3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="42 42"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="42 -42 -42 "; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="4222-4222"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="99999999999999999999999999"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-99999999999999999999999999"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="0 -0 1 -1"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="0 +0 1 -1"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="111+111 -4 3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="+"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="--123 1 321"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="++123 1 321"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="0000000000000000000000009 000000000000000000000009"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="00000001 1 9 3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="00000003 003 9 1"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="--21345"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="1 01"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-000 -0000"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="-00042 -000042"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="42 a 41"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="42 41 40 45 101 x 202 -1 224 3"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
echo "" >> output2.txt; ARG="42 -2 10 11 0 90 45 500 -200 e"; echo -n "\"$ARG\": " >> output2.txt; ./checker_linux $ARG 2>&1 | cat >> output2.txt
make fclean;