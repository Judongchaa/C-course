#include <stdio.h>
#include <string.h>

int main(void) {
    char *text = "Hello World";
    int len = strlen(text);
    for (int i=0; i<len; i++) {
        putchar(text[i]);
    }
    return 0;
}
