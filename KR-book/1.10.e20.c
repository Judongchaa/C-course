#include <stdio.h>

#define TABSPACING 10
#define MAXLINE 100

int main() {
    int i = 0, c;
    
    char string[MAXLINE];

    while ((c = getchar()) != EOF) {
     
        if(c == ' ') {
            while(((i % TABSPACING) != 0) && (i < (MAXLINE - 1))) {
                string[i] = ' ';
                i++;
            }
        } else if (c == '\n') {
            break;
        } else {
            string[i] = c;
            i++;
        }                
    }
    
    string[i] = '\0';

    printf("%s", string);
    
}
