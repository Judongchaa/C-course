#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

double ans;

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case ANS:
            push(ans);
            break;
        case PRINT:
            print();
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
            break;
        case COS:
            push(cos(pop()));
            ans = result();
            break;
        case SIN:
            push(sin(pop()));
            ans = result();
            break;
        case EXP:
            push(exp(pop()));
            ans = result();
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            ans = result();
            break;
        case '+':
            push(pop() + pop());
            ans = result();
            break;
        case '*':
            push(pop() * pop());
            ans = result();
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            ans = result();
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
                ans = result();
            } else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            ans = result();
            break;
        case '\n':
            break;
        case QUIT:
            printf("Exiting the program...\n");
            return 0;
        default:
            printf("error: unknown command %s\n", s);
            break;
    }
  }
  return 0;
}
