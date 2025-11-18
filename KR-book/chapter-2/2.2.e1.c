#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define STEP 2
#define PRECISION 0.01

void int_limits(int num, int step);
void float_limits(float num,float step);

int main(void) {
    int intNum = 0;
    signed int sIntNum = 0;
    
    float floatNum = 1;
    printf("FLT_MAX       = %e\n", FLT_MAX);
    float_limits(floatNum, STEP);
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

void float_limits(float num, float step) {   
    while(step >= 1) {
        
    	if(isinf(num*step)) {
	    	step -= 0.0000001;
            continue;
        }
    	num *= step;
        printf("%e\n",num);
    }
    printf("Maximum value of float: %e\n", num);
}
