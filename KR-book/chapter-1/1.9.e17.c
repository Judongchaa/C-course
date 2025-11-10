#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */
#define MINCHARACTERS 8
#define MAXLINELIST 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len;            /* current line length */
    int position;       /* current number of line registered */
    char line[MAXLINE]; /* current input line */
    char line_list[MAXLINELIST][MAXLINE]; /* list of lines saved here */

    position = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > MINCHARACTERS) {
            copy(line_list[position], line);
            position++;
        }

/* there was a line, it stops to read from the array at the first \0
 * the %s format specification in printf expects the argument to be a string
 */
    printf("\nQueste sono le tue frasi con più di %d caratteri:", MINCHARACTERS);
    while (position) {
        position--;
        printf("\n%s",line_list[position]);       
    }
    return 0;
}

/* getline: read a line into s, return length 
 * 
 * arrays are passed by the pointers, you don't need to return them
 * al long asd you have the address stored.
 */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i)
        if (i < (lim - 1)) {
            s[i] = c; 
        }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;

}

