#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int temp;
    int len = strlen(s) - 1;

    for (int i=0; i<len; i++, len--) {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
    }
}


void itob(int n, char s[], int base) {
    int i = 0;

    while(n!=0) {
        char converted = n % base;
        
        if (converted > 10) {
            s[i++] = converted-10 + 'A';
        } else {
            s[i++] = converted + '0';
        }
        n /= base;
    }
    s[i++] = '\0';
    reverse(s);
}

int main(void) {

    int n = 59;
    int base = 16;   
    char s[10];

    itob(n, s, base);

    printf("%s\n", s);
}