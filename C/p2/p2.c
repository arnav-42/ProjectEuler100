#include <stdio.h>
#include <math.h>

//int fibonacci(int index);
double binet(double n);
double inverse_binet(double f);

int main(void) {
    /* for testing only
    for(int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, fibonacci(i));
        } */
    printf("%f\n", inverse_binet(4000000.0)); // => 33.262948.....
    printf("%f, %f\n", binet(33.0), binet(34.0)); // => ~3.5mil, 5.7mil => 33 is correct index

    double sum = 0;
    for(int i = 3; i <= 33; i+=3) {
        sum += binet(i);
    }

    printf("%f\n", sum);
}

double binet(double n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    return (pow(phi, n) - pow(psi, n)) / sqrt(5);
}

double inverse_binet(double f) {
    double phi = (1 + sqrt(5)) / 2;
    return log(f * sqrt(5)) / log(phi);
}

/*
int fibonacci(int index) {
    switch(index) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(index-2) + fibonacci(index-1);
    }
}

*/
