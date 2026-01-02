#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(void)
{
    int result = 1;

    for (int i = 1; i <= 20; i++) {
        result = lcm(result, i);
    }

    printf("%d\n", result);
    return 0;
}

inline int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

inline int gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
