#include <stdio.h>
#include <stdlib.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z);
void print_array(const int *result, size_t len);

int main()
{
    const int arr1[] = {1, 2, 2};
    const int arr2[] = {2};
    size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t n2 = sizeof(arr2) / sizeof(arr2[0]);
    size_t len = 0;
    size_t *z = &len;

    int *result = array_diff(arr1, n1, arr2, n2, z);
    print_array(result, *z);
    printf("z = %ld", *z);

    return 0;
}

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
    int len = 0;
    int similar = 0;
    for (int n = 0; (unsigned long)n < n1; n++) {
        for (int m = 0; (unsigned long)m < n2; m++) {
            if (arr1[n] == arr2[m]) {
                similar = 1;
            }
        }
        if (similar == 0) {
            len++;
        }
        similar = 0;
    }

    *z = len;
    int *result = (int*)malloc(sizeof(int) * len);
    int pos = 0;
    for (int n = 0; (unsigned long)n < n1; n++) {
        for (int m = 0; (unsigned long)m < n2; m++) {
            if (arr1[n] == arr2[m]) {
                similar = 1;
            }
        }
        if (similar == 0) {
            result[pos] = arr1[n];
            pos++;
        } 
        similar = 0;
    }
    
    return result;
}

void print_array(const int *result, size_t len)
{
    printf("[ ");
    for (int n = 0; n < len; n++) {
        printf("%d ", result[n]);
    }
    printf("]\n");
}