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
