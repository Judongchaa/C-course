#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

struct Commmands {
    char NAME[20];
    int VALUE;
};


int getop(char s[]) {
    int i = 0;
    static int c;

    struct Commmands inputs[N_INPUTS] = {
        {"PRINT", PRINT},
        {"DUPLICATE", DUPLICATE},
        {"SWAP", SWAP},
        {"CLEAR", CLEAR},
        {"QUIT", QUIT},
        {"ANS", ANS},
        {"sin", SIN},
        {"cos", COS},
        {"pow", POW},
        {"exp", EXP}};

    /* brings the first non tab/blank char at index 0 */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* here we check for the input type:
     * - alpha => is a function that modifies the stack or a variable
     * - non digit => standard math operators
     * - digits    => natural numbers */
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';

        for (int j = 0; j<N_INPUTS; j++) {
            if (!strcmp(inputs[j].NAME, s))
                return inputs[j].VALUE;
        }
    }
    // Check for math signs
    if (!isdigit(c) && c != '.') {
        if (c == '-') {
            int next = getch();
            if (isdigit(next) || next == '.') {
                s[++i] = c = next;
            } else {
                if (next != EOF)
                    ungetch(next); // Put the non-digit back
                return '-';        // It was just a subtraction operator
            }
        } else {
            return c; // It's a different operator (*, /, etc.)
        }
    }

    /*/ collects the digits of the number, including the point */
    while (isdigit(s[++i] = c = getch()) || (c == '.'));
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
