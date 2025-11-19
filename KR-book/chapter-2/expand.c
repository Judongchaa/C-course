#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    
    int lent = strlen(s1);
    char *sptr = s2;

    for(int i=0; i<lent; i++) {
        if(s1[i] == '-' && (i!=0 || i!=(lent-1))) {

            if(isdigit(s1[i-1]) && isdigit(s1[i+1])) {
                for(int n = s1[i-1] + 1; n<s1[i+1]; n++) {
                    *sptr++ = '-'; 
                    *sptr++ = n;
                }
            }

            if(isupper(s1[i-1]) && isupper(s1[i+1])) {
                for(int n = s1[i-1] + 1; n<s1[i+1]; n++) {
                    *sptr++ = '-'; 
                    *sptr++ = n;
                }
            }

            if(islower(s1[i-1]) && islower(s1[i+1])) {
                for(int n = s1[i-1] + 1; n<s1[i+1]; n++) {
                    *sptr++ = '-'; 
                    *sptr++ = n;
                }
            }


        }
        *sptr++ = s1[i];
    }
    *sptr++ = '\0';

}

int main(void) {
    char s1[] = "-ciao a-f come 3-8- stai -F-N0-3 tu a-c-d\n";
    char s2[200];

    expand(s1, s2);

    printf("%s", s2);
}
