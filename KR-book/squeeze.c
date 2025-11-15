#include <stdio.h>
#include <string.h>

void squeeze(char t[], char s[]);

int main(void) {
    char t[] = "Hello World";
    char s[] = "Hello Cazzo";

    squeeze(t, s);
}

void squeeze(char t[], char s[]) {

    int len = strlen(t);
    int outPos, i = 0;
    char output[100];

    while (i<len) {
        if (t[i] == s[i]) continue; 
        output[outPos++];
    }     

    printf("%s", output)

}
