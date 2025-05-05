#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *DuplicateEncoder (const char *string);

int main()
{
    char string[] = "aaab";
    char *new_string = DuplicateEncoder(string);
    printf("%s\n", new_string);
}

char *DuplicateEncoder (const char *string)
{
    int len = strlen(string);
    // + 1 for '\0'
    char *new_string = (char*)calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (tolower(string[i]) == tolower(string[j]) && i != j) {
                new_string[i] = ')';
                break;
            } else {
                new_string[i] = '(';
            }
        }
    }
    // return a nul-terminated, heap-allocated string
    return new_string;
}