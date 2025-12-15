#include <ctype.h>
#include <stdio.h>

#define SIZE 20
#define iprint(expr) printf(#expr " = %d\n", expr)

int getint(int *pn);

int main(void) {
    int n, i;
    int array[SIZE] = {0};

    printf("Enter input (e.g., '123 45 -6'):\n");

    // The input loop
    for (n = 0; n < SIZE && getint(&array[n]); n++)
        ;

    printf("\nParsed Integers:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getchar())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getchar();

    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}
