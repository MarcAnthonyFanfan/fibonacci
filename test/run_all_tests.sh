#!/bin/bash
mkdir temp
for i in {-1..47}; do ../bin/fib $i > ../temp/t$i.txt; done
for i in {-1..47}; do
	TEST_DIFF=$(diff ./t${i}.txt ../temp/t${i}.txt)
	if [[ -n $TEST_DIFF ]]; then
		printf "FAILED TEST Fib(${i})\nOUTPUT:\n${TEST_DIFF}\n"
	else
		printf "PASSED TEST Fib(${i})\n"
	fi
done
rm -rf ../temp
