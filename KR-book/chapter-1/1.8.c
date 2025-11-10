#include <stdio.h>

int power(int m, int n);

/* test power function */
int main() {
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
		return 0;
}

/*
 * power: raise base to n-th power; n >= 0 
 *
 * tryng to use less variables to take advantage of local
 * variables in C. Modifyng the n variable doesn't affect the 
 * value of n in the main function
 *
 */

int power(int base, int n) {
    for (int p = 1; n>0; n--) {
		p = p * base;
	}
	return p;
}
