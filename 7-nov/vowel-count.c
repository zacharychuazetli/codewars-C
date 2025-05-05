#include <stddef.h>
#include <stdio.h>
// stddef.h used for size_t, which is unsigned integer for sizes


size_t get_count(const char *s);

int main()
{
    const char string[]= "pear tree";
    size_t num_vowels = get_count(string);
    printf("num_vowels: %ld\n", num_vowels);

    return 0;
}

size_t get_count(const char *s)
{
    // ptr is a pointer pointing to a char, and the character pointed by ptr is constant
    // can also just directly use s
    const char *ptr = s;
    size_t num_vowels = 0;
    while (*ptr != '\0'){
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
        {
            num_vowels += 1;
        }
        ptr += 1;
    }
   
    return num_vowels;
}