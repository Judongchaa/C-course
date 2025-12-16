#include <ctype.h>
#include <stdio.h>

#define SIZE 20
#define iprint(expr) printf(#expr " = %d\n", expr)
#define fprint(expr) printf(#expr " = %f\n", expr)

int getfloat(float *pn);

int main(void) {
    int n, i;
    float array[SIZE] = {0};

    printf("Enter input:\n");

    // The input loop
    for (n = 0; n < SIZE && getfloat(&array[n]); n++)
        ;

    printf("\nParsed Integers:\n");
    for (i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");

    return 0;
}


/* getint: get next integer from input into *pn */
int getfloat(float *pn) {
    int c, sign;
    while (isspace(c = getchar())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getchar();
        if (!isdigit(c)) {
            ungetc(c, stdin);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');

    if (c == '.') {
        c = getchar();
        float n;
        for (n = 10; isdigit(c); c = getchar(), n *= 10) {
            *pn = *pn + (c - '0')/n;
        }
        fprint(*pn);
    }


    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}
