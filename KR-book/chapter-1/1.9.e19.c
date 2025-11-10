#include <stdio.h>

#define MAXLINE 100

int get_line(char string[]);
void reverse(char string[], int len);

int main() {

    int len, loop;
    char line[MAXLINE];

    do {
        len = get_line(line, &loop);
        if (len>0) 
            reverse(line, len);
    } while (loop);

}

int get_line(char string[], int *loop) {
    
    int len, c;
     
    len = 0;

    while(len < (MAXLINE - 1)) {
        c = getchar();

        if (c == '\n') {
            string[len] = c;
            break;
        }

        if (c == EOF) {
            string[len] = c;
            break;
        }
        
        string[len] = c;
        len++;
    }

    string[len] = '\0';
    
    return len;
}

void reverse(char string[], int len) {

    char reversed[len];

    for(int i = 0; i <= len; i++) {
        reversed[i] = string[len-i]; /* len-i is the lastest character not yet tested of the string */ 
    }

    printf("%s\n", reversed);

}
