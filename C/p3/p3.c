#include <stdio.h>

int main(void) {
    long int num = 600851475143;
    int i = 3;
    while(num > 1 && i * i <= num) {
        if (!(num % i)) {
            printf("%d\n", i);
            num /= i;
        }
        else i += 2;
    }

    printf("%ld\n", num);
}
