#include <stdio.h>
#include <math.h>
#include <time.h>

int nth_prime(int n, int N, char is_prime[]);

int main(void) {

    clock_t start = clock();

    int N = (int)(10001 * (log(10001) + log(log(10001)))) + 10; //upper bound of estimate of nth prime
    int size = (N - 1) / 2;
    char is_prime[size];

    for (int i = 0; i < size; i++) is_prime[i] = 1;

    for (int i = 0; (2*i + 3) * (2*i + 3) <= N; i++) {
        if (is_prime[i]) {
            int p = 2*i + 3;
            int start = (p*p - 3) / 2;
            for (int j = start; j < size; j += p)
                is_prime[j] = 0;
        }
    }


    clock_t finish = clock();
    printf("%d\n", nth_prime(10001, N, is_prime));
    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);

    return 0;

}

int nth_prime(int n, int N, char is_prime[]) {
    if (n == 1) return 2;

    int count = 1; // we already counted prime = 2
    for (int i = 0; 2*i + 3 <= N; i++) {
        if (is_prime[i]) {
            count++;
            if (count == n) return 2*i + 3;
        }
    }
    return -1; // not found within limit N
}
