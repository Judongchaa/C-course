#include <stdio.h>

unsigned char invert(unsigned char x, char p, char n) {

    unsigned char mask = ~(~0 << n);
    mask = mask << (p-n+1);

    return x ^ mask;
}

int main(void) {
    unsigned char x = 10;
    char n = 3;
    char p = 4;

    int value = invert(x,p,n);
    printf("%d\n", value);

    return 0;
}


