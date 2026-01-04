#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
//#include <math.h>

int main(void) {



    clock_t t0 = clock();



    clock_t t1 = clock();



    double cpu_time_used = ((double)(t1 - t0)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);
    return 0;

}
