#include <stdio.h>
#include <stddef.h>

size_t countBits(unsigned value);

int main()
{
    unsigned number = 1234;
    size_t num_of_ones = 0;
    num_of_ones = countBits(number);
    printf("%ld\n", num_of_ones);
    return 0;
}

size_t countBits(unsigned value)
{
    int remainder = 0;
    int count = 0;
    while(value != 0) {
        remainder = value % 2;
        if (remainder == 1) {
            count++;
        }
        value /= 2;
        remainder = 0;
    }
	return count;
}