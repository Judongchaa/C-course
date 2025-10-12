#include <stdio.h>

// Parentesys in the while loop are necessary.
// The =! operator ha precedence over the = operator.
// 
// Without the parentheses the preogram would be read like this:
//  (c = (getchar() != EOF))

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
