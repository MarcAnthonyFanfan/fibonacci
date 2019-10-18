#include <stdio.h>
#include <stdlib.h>
#define MAX_FIB 46

int g_num;
int* g_memo;

void print_fib();
int fib(int n);
int error(int e);

int main(int argc, char *argv[]) { 
	g_memo = (int*)calloc(MAX_FIB+1, sizeof(int));
	if(argc != 2) {
		return error(1);
	}
	else {
		g_num = atoi(argv[1]);
		if(g_num < 0) {
			error(2);
		}
		else if(g_num > MAX_FIB) {
			error(3);
		}
		else {
			print_fib();
			return 0;
		}
	}
}

void print_fib() {
	int fib_n = fib(g_num);
	printf("Fib(%d) = %d\n", g_num, fib_n);
	return;
}

int fib(int n) {
	if(g_memo[n] == 0) {
		int calculated = 0;
		if(n == 0 || n == 1) {
			calculated = n;
		}
		else {
			calculated = fib(n-1) + fib(n-2);
		}
		g_memo[n] = calculated;
		return calculated;
	}
	else {
		return g_memo[n];
	}
}

int error(int e) {
	if(e == 1) {
		printf("ARGUMENT ERROR\nPlease run as:\n./fib <#>\nWhere <#> is an integer\n");
	}
	else if(e == 2) {
		printf("ARGUMENT ERROR\n<#> supplied less than 0\nCannot calculate Fib() of a negative number\n");
	}
	else if(e == 3) {
		printf(
			"OVERFLOW ERROR\nFib(%d) too large\nThe max I can calculate is Fib(%d)\n",
			g_num,
			MAX_FIB
		);
	}
	else {
		printf("UNKNOWN ERROR CODE: %d\n", e);
	}
	return e;
}
