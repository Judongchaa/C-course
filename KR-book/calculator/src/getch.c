#include <stdio.h>

static int buf = 0;

int getch(void) {
    int c;

    if (buf != 0) {
        c = buf;
        buf = 0;
        return c;
    }
    return getchar();
}

void ungetch(int c){
    if (buf > 0)
        printf("error: buffer is already full");
    else
        buf = c;
}
