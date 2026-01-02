#include <stdio.h>
#include <time.h>


int main(void) {
    clock_t start = clock();

    int sumsq = 0;
    int sqsum = 0;

    for(int i = 1; i <= 100; i++) sumsq += i*i;
    for(int i = 1; i <= 100; i++) sqsum += i;
    sqsum *= sqsum;

    int result = sqsum - sumsq;
    clock_t finish = clock();
    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;

    printf("%d - %d = %d\n", sqsum, sumsq, result);
    printf("Time: %f seconds\n", cpu_time_used);

}
