#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

/* there was a line, it stops to read from the array at the first \0
 * the %s format specification in printf expects the argument to be a string
 */
    if (max > 0) 
        printf("\n%s\n", longest);

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
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

