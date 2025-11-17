#include <stdio.h>
#include <string.h>

void squeeze(char t[], char s[]);

int main(void) {
    char t[] = "Hello World Word";
    char s[] = "Hello Cazzo        ji";

    squeeze(t, s);
}

void squeeze(char t[], char s[]) {

    int len = strlen(t);
    int outPos = 0;
    char output[100];

    for (int i=0; i<len; i++) {
        if (t[i] != s[i]) output[outPos++] = t[i];
    }     

    printf("%s", output);

}
