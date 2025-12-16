#include <stdio.h>

void pstrcat(char *s, char *t) {
    while(*++s != '\0')
        printf("%p\n", s);

    while((*s++ = *t++) != '\0')
        printf("%p\n", s);
    *s = '\0';
}

int main(void) {
    char s[] = "Hello ";
    char t[] = "World!";

    pstrcat(s, t);

    printf("%s\n", s);
}
