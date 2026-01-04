#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
#include <time.h>

int main(void) {

    int nums[20][20];
    FILE *fp;
    fp = fopen("input.txt", "r");

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(fscanf(fp, "%d", &nums[i][j]) != 1) {
                return 1;
            }
        }
    }
    fclose(fp);
    //printf("%d", nums[1][3]);

    clock_t start = clock();

    long long max = 0;
    int beg_i = 0;
    int end_i = 0;
    int beg_j = 0;
    int end_j = 0;

    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j < 20; j++) {
            long long prod = 1;
            for (int t = 0; t < 4; t++) prod *= nums[i + t][j];
            if (prod > max) {
                max = prod;
                beg_i=i;
                beg_j=j;
                end_i=i+3;
                end_j=j;
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j <= 16; j++) {
            long long prod = 1;
            for (int t = 0; t < 4; t++) prod *= nums[i][j + t];
            if (prod > max) {
                max = prod;
                beg_i=i;
                beg_j=j;
                end_i=i;
                end_j=j+3;
            }
        }
    }

    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 16; j++) {
            long long prod = 1;
            for (int t = 0; t < 4; t++) prod *= nums[i + t][j + t];
            if (prod > max) {
                max = prod;
                beg_i=i;
                beg_j=j;
                end_i=i+3;
                end_j=j+3;
            }
        }
    }

    for (int i = 0; i <= 16; i++) {
        for (int j = 3; j < 20; j++) {
            long long prod = 1;
            for (int t = 0; t < 4; t++) prod *= nums[i + t][j - t];
            if (prod > max) {
                max = prod;
                beg_i=i;
                beg_j=j;
                end_i=i+3;
                end_j=j-3;
            }
        }
    }


    clock_t finish = clock();
    printf("(%d, %d) to (%d, %d) yields %lld\n", beg_j, beg_i, end_j, end_i, max);
    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", cpu_time_used);

    return 0;

}
