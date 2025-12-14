#include <ctype.h>
#include <stdio.h>

#define SIZE 20

int getint(int *pn);
int getch(void);
void ungetch(int);

int main (void) {
    int n, i;
    int array[SIZE] = {0};

    printf("Enter input (e.g., '123 45 -6'):\n");

    // The input loop
    for (n = 0; n < SIZE;) {
        getint(&array[n]);
        int c = array[n];
        if (c != 0)
            n++;
        if (c == '\n')
            break;
    }

    printf("\nParsed Integers:\n");
    for (i = 0; i <= n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())); /* skip white space */

  if (c == '\n'){
      return '\n';
  }

  if (!isdigit(c) && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;
  if (c != '\n') ungetch(c);
  return c;
}


int buf = 0;

int getch(void) {
    int temp;

    if (buf != 0) {
        int temp = buf;
        buf = 0;
        return temp;
    } else
        return getchar();
}

void ungetch(int c) {
    if (buf != 0) {
        printf("Error: Buffer overflow");
        return;
    }

    buf = c;
}
