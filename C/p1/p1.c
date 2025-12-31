#include <stdio.h>

int main(void) {
    int sum3 =  333 * 334 / 2;
    int sum5 = 999 / 5 * (999 / 5 + 1) / 2;
    int sum15 = 999 / 15 * (999 / 15 + 1) / 2; // overlap

    printf("%d", 3 * sum3 + 5 * sum5 - 15 * sum15);
}
