#include <stdio.h>
#include "calc.h"

int sp = 0;
double val[MAXVAL];
extern double ans;

double result(void) {
    ans = pop();
    printf("\t%.3g\n", ans);

    return ans;
}
/* push: puts the inserted double as the last element of the stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/* peek: prints the last value of the stack, without moving the sp */
void peek(void){
    if(sp>0) {
        printf("\t%.3g\n",  val[sp-1]);
    }
}
/* print: prints all element of the stack without modifing them */
void print(void) {
    printf("These are the %d elements of the stack: ", sp+1);
    for (int i = 0; i<=sp; i++) {
        printf("%.3g ", val[i]);

    }
    printf("\n");
}
/* duplicate: duplicates the last element of the stack */
void duplicate(void) {
    if (sp > 0) {
        push(val[sp-1]);
        printf("Duplicated value %g\n", val[sp]);
    } else {
        printf("error: stack empty\n");
    }
}
/* swap: swapped the last two elements of the stack */
void swap(void) {
    double tmp = val[0];
    val[0] = val[1];
    val[1] = tmp;
    printf("Swapped values %g and %g\n", val[0], val[1]);
}
/* clear: clears the array */
void clear(void) {
    sp = 0;
    val[sp] = 0;
    printf("Stack cleared.\n");
}
