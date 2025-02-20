#include <stdio.h>
#include <stddef.h>

int find_odd (size_t length, const int array[length]);

int main()
{
    const int array[] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    size_t length = sizeof(array)/sizeof(array[0]);
    int result = find_odd(length, array);
    printf("Number is: %d", result);
    return 0;
}

int find_odd (size_t length, const int array[length])
{
    int count = 0;
    for (int n = 0; n < length; n++) {
        for (int m = 0; m < length; m++) {
            if (array[m] == array[n]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return array[n];
        } else {
            count = 0;
        }
    }
}