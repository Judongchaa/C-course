#include <stdio.h>

int len(char *s) {
    int len;
    for(len=0; *s++ != '\0'; len++)
        ;
    return len;

}

int strindex(char *s, char *t) {
    int index = -1;
    int tlen = len(t);

    char *sstart = s;
    char *tstart = t;

    if (tlen == 0) return -1;

    for( ;*s != '\0'; s++) {
        for(char *copy = s; *copy++ == *t++; ) {
            if (copy-s == tlen) index = s-sstart;
        }
        t = tstart;
    }

    return index;
}

int main(void) {
    char s[] = "Hello World ciaorororsa ";
    char t[] = "oror";

    int out = strindex(s, t);

    printf("%d\n", out);
}
