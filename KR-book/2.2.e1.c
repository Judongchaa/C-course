#include <stdio.h>
#include <limits.h>

#define STEP 10000
#define PRECISION 0.01

void int_limits(int num, int step);

int main(void) {
    int intNum = 0;
    signed int sIntNum = 0;

    printf("%d\n", INT_MAX);

    max_int = int_limits(intNum, STEP);
    min_int = int_limits(sIntNUm, -STEP);
}

void int_limits(int num, int step) {

    int oldNum = num;
    while(step >= 1) {
	if(num+step > oldNum) {
		num += step;
		oldNum = num;
	} else {
		step--;
	}
	        
    }

    printf("Maximum value of int: %d\n", num);

}


