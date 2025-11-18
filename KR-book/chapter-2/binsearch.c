#include <stdio.h>
#include <time.h>



/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    
    int low, high, mid;
    
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high)/2;        
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }

    if (x == v[high]) return high;
    if (x == v[low]) return low;

    return -1; /* no match */
}

int main(void) {
    clock_t begin = clock();

    int n = 10;
    int x = 15;

    int v[] = {1, 2, 4, 6, 8, 9, 10, 15, 30, 40};

    int pos = binsearch(x, v, n);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("%f\n", time_spent);
    printf("%d\n", pos);

}