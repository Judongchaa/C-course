#include <stdio.h>

/* 
 * simple program to start learning the math behind pointers
 * 
 * mystr is an array, but if you pass its value to a char pointer
 * it is the memory address where it is located. Every time to add 1 to 
 * the pointer it skips to next byte*byte_size declared in the pointer. 
*/

int main(void) {
	char mystr[] = "AABBCCDDEEFF";
        char *p = mystr;

	printf("p is located in %p\n",p);

	while (*p != 0) {
		putchar(p[0]);
		p++;		
	}
	printf("\n");	

	printf("p is located at in %p\n", mystr);
	return 0;
}
