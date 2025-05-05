#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *alphabet_position(const char *text);

int main() {
    const char text[] = "tkiqet.";
    char *output = alphabet_position(text);
    printf("%s\n", output);
}

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
    size_t len = strlen(text);
    int count = 0;
    int ascii_value = 0;
    // a = 97 in ascii table
    // a = 97, z = 122
    for (size_t i = 0; i < len; i++) {
        ascii_value = tolower(text[i]);
        if (ascii_value >= 97 && ascii_value <= 122) {
            // need to minus 96 to get the alphabet number
            // 105-96 = 9, so anything above 105 needs 3 spaces (including ' ')
            // anything below needs 2 spaces
            if (ascii_value <= 105) {
                count = count + 2;
            } else {
                count = count + 3;
            }
        }
    }
    char *output = (char*)calloc(count, sizeof(char));
    char *buffer;
    for (size_t i = 0; i < len; i++) {
        ascii_value = tolower(text[i]);
        if (ascii_value >= 97 && ascii_value <= 122) {
            if (ascii_value >= 10){
                // need to declar buffer outside the if loop
                // because if not the buffer declared inside the if loop
                // is not the same as outside the loop
                buffer = (char*)calloc(3, sizeof(char));
            } else {
                buffer = (char*)calloc(2, sizeof(char));
            }
            sprintf(buffer, "%d ", ascii_value - 96);
            strcat(output, buffer);
            free(buffer);
        }
    }
    output[count-1] = '\0';
    return output;
}