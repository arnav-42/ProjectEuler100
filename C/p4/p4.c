#include <stdio.h>
#include <time.h>

int main(void) {
    int max = 998001; // 999 * 999
    int max11 = max - (max % 11); //997997
    int beg = 0;
    int end = 0;
    int maxp = 0;
    int ff = 0;
    clock_t start = clock();
    for (int i = max11; i >= 100000; i-=11) {
        beg = i / 1000;
        end = i % 1000;
        if((beg) != (100*(end%10) + 10*((end/10)%10) + (end/100))) continue;
        for(int j = 999; j > 0; j--) {
            if((i%j == 0) && (i/j >= 100) && (i/j <= 999)) {
                clock_t finish = clock();
                double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;
                printf("%d and %d gives %d\n",j, i/j, i);
                printf("Time: %f seconds\n", cpu_time_used);
                goto done;
            }
        }
    }

    done: printf("done");
}
