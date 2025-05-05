#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void to_camel_case(const char *text, char *camel);

int main() {
    const char text[] = "The_Stealth_Warrior";
    char *camel = (char*)calloc(strlen(text)+1, sizeof(char));
    to_camel_case(text, camel);
    printf("%s\n", camel);
    return 0;
}

//  do not allocate memory for the result
//  write to pre-allocated pointer *camel
void to_camel_case(const char *text, char *camel) {
    int upper_flag = 0;
    while(*text) {
        if ((*text == '-' || *text == '_') && (*(text + 1) != '\0')) {
            text++;
            upper_flag = 1;
        } 
        if (upper_flag == 1) {
            *camel = toupper(*text);
            upper_flag = 0;
        } else {
            *camel = *text;
        }
        text++;
        camel++;
    }
    *camel = '\0';
}