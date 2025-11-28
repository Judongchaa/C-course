#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
    int temp;
    int len = strlen(s) - 1;

    for (int i=0; i<len; i++, len--) {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
    }
}

/* itoa: convert n to characters in s */
void itoa(char n, char s[]) {
    char i, sign;
    i = 0;

    sign = (n>=0) ? 1 : -1;

    do {
        s[i++] = sign*(n % 10) + '0'; /* get next digit */
    } while (sign*(n /= 10) > 0); /* delete it */

    if(sign<0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char n = 20;
    char s[20];

    itoa(n, s);

    printf("%s\n", s);
}
