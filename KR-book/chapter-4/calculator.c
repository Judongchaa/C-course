#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define N_INPUTS 20
#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER 1
#define PRINT 'a'
#define DUPLICATE 'b'
#define SWAP 'c'
#define CLEAR 'd'
#define ANS 'e'
#define COS 'f'
#define SIN 'g'
#define POW 'h'
#define EXP 'i'
#define QUIT 'j'

int getop(char []);
void push(double);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
double pop(void);
int getch(void);
void ungetch(int);
void peek(void);
double result(void);

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

int sp = 0;
double val[MAXVAL];

struct Commmands {
    char NAME[20];
    int VALUE;
};

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

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i = 0, c;

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
     * - uppercase => is a function that modifies the stack or a variable
     * - lowercase => math.h functions
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

int buf = 0;

int getch(void) {
    int c;

    if (buf != 0) {
        c = buf;
        buf = 0;
        return c;
    }
    return getchar();
}

void ungetch(int c){
    if (buf > 0)
        printf("error: buffer is already full");
    else
        buf = c;
}
