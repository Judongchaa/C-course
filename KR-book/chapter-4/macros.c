/* Simplest macro, if ti finds a PI it
 * substitutes it with the sequent value */
#define PI 3.14159

/* It's better than a fuction because the
 * program doesn-t need to reach the heap */
#define MAX(A, B) ((A) > (B) ? (A) : (B))

/* Defines a debug print that prints the
 * variable name AND its value  */
#define DPRINT(expr) printf(#expr " = %d\n", expr)

/* Creates a variable name like "student_1", "student_2" */
#define MAKE_STUDENT(id)  int student_##id
