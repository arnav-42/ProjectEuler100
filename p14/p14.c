#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
//#include <math.h>

int main(void) {
    clock_t t0 = clock();

    int count;
    int max = 0;
    int max_i = 0;
    for(int i = 999999; i > 499999; i--) {
        count = 0;
        for(long j = i; j != 1;) {
            if(j & 1) {
                j = 3 * j + 1;
            }
            else {
                j /= 2;
            }
            count++;
        }
        if(count > max) {
            max = count;
            max_i = i;
        }
    }

    clock_t t1 = clock();
    printf("%d took %d steps", max_i, max);
    double cpu_time_used = ((double)(t1 - t0)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);
    return 0;

}
