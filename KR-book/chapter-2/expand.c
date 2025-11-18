#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    
    int lent = strlen(s1);
    char *sptr = s2;

    for(int i=1; i<lent; i++) {
        if(s1[i] == '-') {
            if(isDigit(s[i-1]) && isDigit(s[i+1])) {


            }
        }

    }

}

int main(void) {
    char s1[] = "ciao a-f come 3-8- stai -F-N tu a-b-c\n";
    char s2[200];

    expand(s1, s2);

    printf("%s", s2);
}