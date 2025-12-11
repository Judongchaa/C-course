#include <stdio.h>
#include <string.h>

void reverse(char s[], int len, int offset);

int main(void) {
    char s[] = "12345678";
    reverse(s, strlen(s), 0);
    printf("%s\n", s);
}

void reverse(char s[], int len, int offset) {
    int temp;

    if (len <= offset) return;

    temp = s[--len];
    s[len] = s[offset];
    s[offset] = temp;

    reverse(s, len, ++offset);
}
