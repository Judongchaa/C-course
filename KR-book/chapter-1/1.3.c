#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

// from c99 you can declare variables inside the for loop by stating the type erlier.
// these variables will exist only under the loop.


int main() {
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) { 
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

}
