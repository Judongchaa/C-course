#include <stdio.h>

#define NCOLUMN 10
#define MAXLINE 1000

int main() {
    int c, len = 0, col = 0;
    int last_space = -1;

    char string[MAXLINE];
    
    while((c = getchar()) != EOF && c != '\n')  {
    
        string[len] = c;

        if (c == ' ') {
            last_space = len;
        }

        if (col != NCOLUMN-1) {
            col++;
        } else if (last_space > 0) {
            string[last_space] = '\n';
            
            col = 0;
            last_space = -1;
        } else {
            len++;
            string[len] = '-';
            len++;
            string[len] = '\n';
            col = 0;
        }
        len++;
    }
    string[len] = '\0';
    printf("\n%s", string);
}

