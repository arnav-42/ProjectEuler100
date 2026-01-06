#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
//#include <math.h>

int main(void) {



    clock_t t0 = clock();

    long long tri = 1;
    long long divcount= 0;
    for(long long i = 1;;i++) {
        tri = i * (i+1) / 2;
        for(long long j = 2; j*j <= tri; j++) {
            if(tri%j==0) {
                divcount += 2;
            }
            if(divcount > 500) {
                goto finished;

            }
        }
        divcount = 0;
    }

    finished: ;
        clock_t t1 = clock();
        printf("%lld\n", tri);
        double cpu_time_used = ((double)(t1 - t0)) / CLOCKS_PER_SEC;
        printf("Time: %f seconds\n", cpu_time_used);

        return 0;

}
