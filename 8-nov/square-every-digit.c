#include <stdio.h>

unsigned long long square_digits(unsigned n);


int main()
{
    unsigned n = 123;
    unsigned long long result = 0;
    result = square_digits(n);
    printf("%lld\n", result);

    return 0;
}

unsigned long long square_digits (unsigned n)
{
    unsigned long long q = 0;
    unsigned long long m = 1;
    unsigned r;
    do {
        r = n % 10;
        q = q + (r * r * m);
        if (r > 3) {
            m = m * 100;
        } else {
            m = m * 10;
        }
    } while (n = n / 10);
    return q;
}