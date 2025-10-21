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
    
    int lines = 1;
    int last_space;
    
    for(int i = 0; i <= len; i++) {

        if(string[i] == ' ') {
            last_space = i;
        }
        if(((i % NCOLUMN) == 0) && i>0) {
            if(last_space > (lines * NCOLUMN)) {
                string[last_space] = '\n';
                lines++;
            } else {
                move_string(string, i, len, 3);
                string[i] = '=';
                string[i++] = '\n';
//                string[i++] = '=';
            } 
        }
    }

    printf("%s\n", string);
}

void move_string(char string[], int start, int len, int ammount) {

    while(len >= start) {
        string[len+ammount] = string[len];
        len--;
    }
}
