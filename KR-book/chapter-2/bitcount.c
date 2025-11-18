#include <stdio.h>

int bitcount(unsigned char x) {
    int b;
    /* 
        x &= (x-1) deletes the rightmost 1 bit.
        ----------------------------
        x = 16  => 00010000
        x -= 1  => 00001111
        x & x-1 => 00000000
        ----------------------------
        The orignal number becames 0, the cycle stops.
    */
    for(b = 0; x != 0; x &= (x-1)) {
        b++;
    }
    return b;
}

int main(void) {
    unsigned char x = 16;

    int n = bitcount(x);

    printf("%d\n", n);
}
