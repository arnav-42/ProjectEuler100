#include <stdio.h>
//#include <math.h>
#include <time.h>

int main(void) {
    clock_t t0 = clock();

    const int N = 2000000;
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

    long long sum = 0;
    if (N >= 2) sum += 2;

    for (int i = 0; 2 * i + 3 <= N; i++) {
        if (is_prime[i]) sum += (long long)(2 * i + 3);
    }

    clock_t t1 = clock();
    printf("%lld\n", sum);

    double cpu_time_used = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);

    return 0;
}
