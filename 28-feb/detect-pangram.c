#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *str_in);

int main() {
    const char str_in[] = "The quick, brown fox jumps over the lazy dog!";
    bool result = true;
    result = is_pangram(str_in);
    printf("%d\n", result);
    return 0;
}

bool is_pangram(const char *str_in) {
    int ascii_value = 0;
    // a = 97, z = 122
    int len = strlen(str_in);
    for (int i = 97; i < 123; i++) {
        for (int j = 0; j < len; j++) {
            ascii_value = tolower(str_in[j]);
            if (ascii_value == i) {
                break;
            } else if (j == len - 1){
                return false;
            }
        }
    }
    return true;

}