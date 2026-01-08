#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
//#include <math.h>

int main(void) {
    clock_t t0 = clock();

    const int N = 999999;
    const int size = (N - 1) / 2;
    char is_prime[size];
    for (int i = 0; i < size; i++) is_prime[i] = 1;

    for (int i = 0; (2 * i + 3) * (2 * i + 3) <= N; i++) {
        if (is_prime[i]) {
            int p = 2 * i + 3;
            int start = (p * p - 3) / 2;
            for (int j = start; j < size; j += p) {
                is_prime[j] = 0;
            }
        }
    }

    for (int digits = 1; digits <= 6; digits++) {
        int start = (digits == 1) ? 1 : pow(10, digits - 1);
        int end   = pow(10, digits) - 1;

        for (int n = start; n <= end; n++) {
            printf("%d\n", n);
        }
    }

    clock_t t1 = clock();



    double cpu_time_used = ((double)(t1 - t0)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);
    return 0;

}
