#include <stdio.h>
#include <string.h>

#define TFOBJ_TYPE_NUM 0
#define TFOBJ_TYPE_OP 1
#define TFOBJ_TYPE_STR 2
#define TFOBJ_TYPE_LIST 3
#define TFOBJ_STR_MAXLEN 10

/* ============================================= Data Structure ========================================================== */

typedef struct tfobj{
    int refcount;
    int type; // depending on the tfobj type we'll use different data structures
    union {
        int num;  // TFOBJ_TYPE_NUM
        char op;  // TFOBJ_TYPE_OP

        struct {  // TFOBJ_TYPE_STR
            char *symbol;
            int len;
        } str;

        struct {  // TFOBJ_TYPE_LIST
            struct tfobj *stack;
            int len;
        } list;
    };
} tfobj;

/* Struct to define the stack where all operation are going to be processed.
* It is an array of tfobj, which can be num, op, str or list.
*
* The TFOBJ_TYPE_LIST object has the same structure of a tfstack object.
* the stack is the main container, which can contain variius tfobj that can also act
* as a little substacks. */
typedef struct tfstack {
    tfobj stack[50];
    int len;
} tfstack;


/* ============================================== Stack functions ====================================================== */

/* creates a new global stack obj with len 0 */
tfstack* stack_create(void) {
    static tfstack o;
    o.len = 0;

    return &o;
}

/* appends to the last position the tfobj pointed at by tfstack */
void stack_append(tfobj *object, tfstack *st) {
    int len = st->len;
    st->stack[len] = *object;
    (st->len)++;
}

/* pops the tfobj at the last position of the tfstack */
void stack_pop(tfstack *st) {
    (st->len)--;
}

/* recursive function to print every tfobj inside the stack.
* if it finds a TFOBJ_TYPE_LIST it parse it as a tfstack and recall the
* stack_print function */
void stack_print(tfstack *st) {
    int len = st->len;
    tfobj *o = &(st->stack[0]);

    printf("[ ");
    for(int j = 0; j<len; j++, o++) {
        if(o->type == TFOBJ_TYPE_NUM)
            printf ("%d ", o->num);
        else if (o->type == TFOBJ_TYPE_OP)
            printf ("%c ", o->op);
        else if (o->type == TFOBJ_TYPE_STR)
            printf ("%s ", o->str.symbol);
        else
            stack_print((tfstack *) &o->list);
    }
    printf("]");
}


/* ======================================== Data structures functions ================================================ */


tfobj* objdefine(int type) {
    static tfobj o;
    o.type = type;
    o.refcount = 1;

    return &o;
}

void objdup(tfstack *st) {
    int last = st->len -1;
    if (last>=0) {
        (st->stack[last].refcount)++;
        stack_append(&st->stack[last], st);
    }
}

void objnum (int num, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_NUM);
    o -> num = num;

    stack_append(o, st);
}

void objop (char op, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_OP);
    o -> op = op;

    stack_append(o, st);
}


void objsym (char *symbol, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_STR);
    o -> str.symbol = symbol;
    o -> str.len = strlen(symbol);

    stack_append(o, st);
}

void objvar (char *var, tfstack *st) {
    objsym(var, st);
}

tfobj* objlist (void) {
    tfobj *o = objdefine(TFOBJ_TYPE_LIST);
    return o;
}

void tfprint(tfobj *o) {
    if(o->type == TFOBJ_TYPE_NUM) {
        printf ("The obj is the number: %d\n", o->num);
    } else if (o->type != TFOBJ_TYPE_LIST) {
        printf ("The obj is the symbol: %s\n", o->str.symbol);
    }
}

/* ==================================================== MAIN =========================================================== */

int main(int argc, char **argv) {
    // if (argc == 1 || argc > 3) {
    //     fprintf(stderr, "Correct usage: toyforth <cli/open>");
    // }
    // else if (!strcmp(argv[1], "open") ) {
    //     FILE *readfrom = fopen(argv[2], "r");
    //     printf("open");
    //     if (readfrom != NULL) {
    //         // get_element(readfrom);
    //     } else {
    //         fprintf(stderr, "File <%s> cannot be opened", argv[2]);
    //     }
    // }
    // else if (!strcmp(argv[1], "cli")) {
    //     //get_element(stdin);
    //     printf("cli");
    // } else {
    //     fprintf(stderr, "Correct usage: toyforth <cli/open>");
    // }

    tfstack *stack = stack_create();
    objnum(10, stack);
    objsym("ciao", stack);
    objdup(stack);
    objop('f', stack);
    tfobj *list1 = objlist();
    objnum(80, (tfstack *) &list1->list);
    stack_append(list1, stack);

    stack_print(stack);
    printf("\n");
}
