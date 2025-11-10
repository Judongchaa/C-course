#include <stdio.h>

int main(void) {
    double nc;

    nc = 0;
    while (getchar() != "\n") {
        nc++;
    } 
	    printf("%f\n", nc);
}
