#include <stdio.h>

int len(char *s) {
    int len;
    for(len=0; *s++ != '\0'; len++)
        ;
    return len;

}

int pstrend(char *s, char *t) {
    int slen = len(s);
    int tlen = len(t);

    if (tlen>slen) return 0;

    for(s = s+slen-tlen; *s++ == *t++;)
        if (*t == '\0') return 1;

    return 0;

}

int main(void) {
    char s[] = "Hellods ";
    char t[] = "ds  ";

    int out = pstrend(s, t);

    printf("%d\n", out);
}
