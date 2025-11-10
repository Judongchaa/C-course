#include <stdio.h>

// in C integer division truncates the fractal part
//
// the %d rappresents the substituition to an integer. 
// If you augment each %[data_type] in the printf statement with a width, 
// the number printed will be right justified 


int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}
