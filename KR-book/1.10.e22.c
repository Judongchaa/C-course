#include <stdio.h>

#define NCOLUMN 10
#define MAXLINE 1000

void print_line(char string[], int len); 
void move_string(char string[], int start, int len, int ammount);

int main() {
    int c, len = 0;

    char string[MAXLINE] = {'\0'};
    
    while((c = getchar()))  {
        
        if ((c == '\n') || (c == EOF)) {
            break;
        }
        
        string[len] = c;
        len++;
    }

    print_line(string, len);
}

void print_line(char string[], int len) {
    
    int lines, last_space, nchar;
    lines = nchar = 0;
    last_space = -1;

    for(int i = 0; i<len; i++) {
        
        nchar++;

        if (string[i] == ' ') {
            last_space = i;    
        }

        if (nchar == NCOLUMN) {
             if(lastspace != -1) {
                string[last_space] = '\n';

                lines++;
                nchar = 0;
                last_space = -1;
             } else {
                
             
             }
        } 
    }
}

void last_indexs(string[], n_indexs)
