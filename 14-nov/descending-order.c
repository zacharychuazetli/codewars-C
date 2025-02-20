#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t descendingOrder(uint64_t n);

int main()
{
    uint64_t result = 0;
    uint64_t n = 145263;
    result = descendingOrder(n);
    printf("%ld", result);
    return 0;
}

uint64_t descendingOrder(uint64_t n)
{
    int digit = 0;
    int len = 0;
    uint64_t number = n;
    while (number != 0) {
        digit = number % 10;
        len++;
        number /= 10;
    }

    int *array = (int*)malloc(sizeof(int) * len);
    number = n;
    for (int i = 0; i < len; i++) {
        digit = number % 10;
        array[i] = digit;
        number /= 10;
    }

    int tmp = 0;
    int swapped = 0;
    for (int i = 0; i < len - 1; i++) {\
        swapped = 0;
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }

    uint64_t result = 0;
    for (int i = 0; i < len; i++) {
        result = result * 10 + array[i];
    }
    return result;
}

