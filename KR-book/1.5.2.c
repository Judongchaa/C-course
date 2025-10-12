#include <stdio.h>

int main(void) {
    double nc;

    nc = 0;
    while (getchar() != EOF) {
        nc++;
    } 
	    printf("%f\n", nc);
}
