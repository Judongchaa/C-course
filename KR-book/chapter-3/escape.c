#include <stdio.h>
#include <string.h>

void escape(char t[], char s[]) {

    int lent = strlen(t);
    char* sptr = s;

    for(int i = 0;  i<lent; i++) {
        switch (t[i]) {
            case '\n':
                *sptr++ = '\\';
                *sptr++ = 'n';
                break;
            case '\t':
                *sptr++ = '\\';
                *sptr++ = 't';
                break;
            default:
                *sptr++ = t[i];
        }
    } 
    *sptr = '\0';
} 

int main(void) {
    char t[] = "Ciao come\tstai\n?\n";
    char s[100];

    escape(t, s);

    printf("%s", s);
}

