#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

size_t duplicate_count(const char *text);

int main() {
    const char text[] = "Indivisibilities";
    size_t count = 0;
    count = duplicate_count(text);
    printf("%ld\n", count);
    return 0;
}
size_t duplicate_count(const char *text) {
    size_t count = 0;
    size_t temp_count = 0;
    size_t length = strlen(text);
    int *flag = (int*)calloc(length, sizeof(int));

    for (size_t i = 0; i < length; i++ ) {
        if (flag[i] == 0) {
            flag[i] = 1;
            for (size_t j = 0; j < length; j++) {
                if (tolower(text[i]) == tolower(text[j]) && i != j) {
                    flag[j] = 1;
                    temp_count++;
                }
            }
            if (temp_count >= 1) {
                count++;
                temp_count = 0;
            }
        }
    }
    return count;
}