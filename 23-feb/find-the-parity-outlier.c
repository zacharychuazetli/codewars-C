#include <stdio.h>
#include <stddef.h>

int find_outlier(const int values[], size_t count);

int main()
{
    int outlier = 0;
    const int array[] = {4, 1, 1};
    size_t count = sizeof(array);
    outlier = find_outlier(array, count);
    printf("%d\n", outlier);
    return 0;
}


int find_outlier(const int values[], size_t count)
{
    // initiate i to size_t to be same as count
    int odd = 0, even = 0, odd_count = 0, even_count = 0, outlier = 0;
    for (size_t i = 0; i < count; i++) {
        if (values[i] % 2 == 0) {
            even = values[i];
            even_count++;
        } else {
            odd = values[i];
            odd_count++;
        }
        if (even_count > 1) {
            if (odd_count == 1) {
                outlier = odd;
                break;
            }
        } else if (odd_count > 1) {
            if (even_count == 1) {
                outlier = even;
                break;
            }
        }
    }
    return outlier;
}