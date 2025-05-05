#include <stdio.h>
#include <stdlib.h>
// this is used for memory allocation

//solution must allocate all required memory
//and return a free-able buffer to the caller.

//malloc vs calloc, calloc initializes to 0, while malloc dont initialize to anything

char *disemvowel(const char *str);

int main()
{
    // this string length can change, so can't statically assign the memory
    // need to allocate dynamically at runtime, use calloc
    const char string[] = "This website is for losers LOL!";
    char* new_string = disemvowel(string);
    printf("New string: %s\n", new_string);

    return 0;
}


char *disemvowel(const char *str)
{
    // can use strlen also
    int len = 0;
    while (str[len] != '\0')
    {
        len += 1;
    } 
    
    // calloc returns void so need to type cast it
    // calloc allocates memory dynamically
    // calloc need two input, first is number of elements to allocate, second is size of each element
    // len + 1, because need one extra space for \0, and sizeof(*str) *str is first element so size of that
    char *new_string = (char*)calloc(len + 1, sizeof(*str));

    int new_count = 0;
    for (int count = 0; str[count] != '\0'; count++) {
        if ((str[count] != 'a' && str[count] != 'e' && str[count] != 'i' && str[count] != 'o' && str[count] != 'u') &&
            (str[count] != 'A' && str[count] != 'E' && str[count] != 'I' && str[count] != 'O' && str[count] != 'U')) {
            new_string[new_count] = str[count];
            new_count++;
        }
    }
    

	return new_string;
}