#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {

    clock_t start = clock();

    int n = 1;
    float m = 4.2;
    for (;;) {
        m = (-n + sqrt(n*n + 2000)) / 2;
        if (m > n && floor(m) == m) break;
        n++;
    }


    clock_t finish = clock();
    printf("m = %d, n = %d\n", (int)m, n);
    printf("a = %d, b = %d, c = %d, a + b + c = %d, abc = %d\n", (int)(m*m-n*n), (int)(2*m*n), (int)(m*m+n*n), (int)(m*m-n*n+2*m*n+m*m+n*n), (int)((m*m-n*n)*2*m*n*(m*m+n*n)));

    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);

    return 0;

}
