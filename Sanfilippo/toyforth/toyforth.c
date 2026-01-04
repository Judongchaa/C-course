#include <alloca.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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
            struct tfobj *stack[3];
            int len;
        } list;
    };
} tfobj;

/* Struct to define the stack where all operation are going to be processed.
* It is an array of tfobj, which can be num, op, str or list.
*
* The TFOBJ_TYPE_LIST object has the same structure of a tfstack object.
* the stack is the main container, which can contain variius tfobj pointers that can also act
* as a little substacks. */
typedef struct tfstack {
    tfobj *stack[50];
    int len;
} tfstack;

/* ========================================== Functions declaration ==================================================== */

void *xmalloc(size_t size);
void objremove(tfobj *o);

/* ============================================== Stack functions ====================================================== */

/* creates a new stack obj in the heap sugin malloc, with len 0 */
tfstack* stack_create(void) {
    tfstack *o = xmalloc(sizeof(tfstack));
    o -> len = 0;

    return o;
}

/* appends to the last position the tfobj pointer to tfstack */
void stack_append(tfobj *object, tfstack *st) {
    int len = st->len;
    st->stack[len] = object;
    (st->len)++;
}

/* pops the tfobj at the last position of the tfstack, freeing the heap */
void stack_pop(tfstack *st) {
    int len = --(st->len);
    tfobj *o = st->stack[len];
    objremove(o); //check the type of the tfobj and acts differently depending on it
}

/* recursive function to print every tfobj inside the stack.
 * if it finds a TFOBJ_TYPE_LIST it parse it as a tfstack and recall the
 * stack_print function                                                  */
void stack_print(tfstack *st) {
    int len = st->len;
    tfobj *o = (st->stack[0]);

    printf(" [");
    for(int j = 0; j<len; j++, o=(st->stack[j])) {
        switch(o->type) {
        case(TFOBJ_TYPE_NUM):
            printf (" %d", o->num);
            break;
        case(TFOBJ_TYPE_OP):
            printf (" %c", o->op);
            break;
        case(TFOBJ_TYPE_STR):
            printf (" %s", o->str.symbol);
            break;
        case(TFOBJ_TYPE_LIST):
            stack_print((tfstack *) &o->list);
        }
    }
    printf(" ]");
}


/* ======================================== tfobj manipulation functions ================================================ */

/* creates a new tfobj in the heap using malloc, with refcount 1 and the passed type */
tfobj* objdefine(int type) {
    tfobj *o = xmalloc(sizeof(tfobj));
    o->type = type;
    o->refcount = 1;

    return o;
}

/* Duplicate the passed pointer, increase the obj refcount and adds the pointer to the last position of the stack */
void objdup(tfstack *st) {
    int last = st->len -1;
    if (last>=0) {
        (st->stack[last]->refcount)++;
        stack_append(st->stack[last], st);
    }
}

tfobj* objnum (int num, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_NUM);
    o -> num = num;

    stack_append(o, st);

    return o;
}

tfobj* objop (char op, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_OP);
    o -> op = op;

    stack_append(o, st);

    return o;
}


tfobj* objsym (char *symbol, tfstack *st) {
    tfobj* o = objdefine(TFOBJ_TYPE_STR);
    o -> str.symbol = symbol;
    o -> str.len = strlen(symbol);

    stack_append(o, st);

    return 0;
}

tfobj* objvar (char *var, tfstack *st) {
    objsym(var, st);

    return 0;
}

tfobj* objlist (void) {
    tfobj *o = objdefine(TFOBJ_TYPE_LIST);
    return o;
}

void objremove(tfobj *o) {
    short type = o->type;

    if(type == TFOBJ_TYPE_NUM ||type == TFOBJ_TYPE_OP) {
        free(o);
    }
    else if (o->type == TFOBJ_TYPE_STR) {
        free(o->str.symbol);
        free(o);
    }
    else {
        for(int i=0; i < o->list.len; i++)
            objremove(o->list.stack[i]);
        free(o);
    }
}

void tfprint(tfobj *o) {
    switch(o->type) {
    case(TFOBJ_TYPE_NUM):
        printf (" %d", o->num);
        break;
    case(TFOBJ_TYPE_OP):
        printf (" %c", o->op);
        break;
    case(TFOBJ_TYPE_STR):
        printf (" %s", o->str.symbol);
        break;
    case(TFOBJ_TYPE_LIST):
        stack_print((tfstack *) &o->list);
    }
}

/* =============================================== Memory rappers ====================================================== */
void *xmalloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Not enought memory");
        free(ptr);
    }

    return ptr;
}

/* ==================================================== Getop() =========================================================== */

void getop(FILE *input, tfstack *stack) {
    char c;
    while((c = getc(input)) != ' ') ;
}

/* ==================================================== MAIN =========================================================== */

int main(int argc, char **argv) {
    tfstack *stack = stack_create();

    if (argc == 1 || argc > 3) {
        fprintf(stderr, "Correct usage: toyforth <cli/open>\n");
    }
    else if (!strcmp(argv[1], "open") ) {
        FILE *readfrom = fopen(argv[2], "r");
        if (readfrom != NULL) {
            getop(readfrom, stack);
        } else {
            fprintf(stderr, "File <%s> cannot be opened\n", argv[2]);
        }
    }
    else if (!strcmp(argv[1], "cli")) {
        getop(stdin, stack);
    } else {
        fprintf(stderr, "Correct usage: toyforth <cli/open>");
    }

}
