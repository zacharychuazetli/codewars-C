#include <stdio.h>

int digital_root(int n);

int main()
{
    int n = 1;
    int result = digital_root(n);
    printf("%d", result);
    return 0;
}

int digital_root(int n) {
    int digit = 0;
    int sum = 0;
    int resultant = 0;
    
    resultant = n;

    do {
        sum = 0;
        while (resultant != 0) {
            digit = resultant % 10;
            sum += digit;
            resultant /= 10;
        }
        resultant = sum;
    } while (sum >= 10);
       
    return sum;
}