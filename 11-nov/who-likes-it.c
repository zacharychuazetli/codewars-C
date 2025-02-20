#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite

char *likes(size_t n, const char *const names[n]);

int main()
{

    const char * const names[] = {"Jacob", "Alex", "hello", "bye", "bye", "bye", "bye"};
    size_t n = sizeof(names)/sizeof(names[0]);
    char *result = likes(n, names);
    printf("%s\n", result);
    free(result);
    return 0;
}

// constant data, constant pointer that is pointing to char
char *likes(size_t n, const char *const names[n]) {
    
    // calloc returns void so need to type cast it 
    char *result, *count_as_str;

    switch(n){
        case 0:
            result = (char*)calloc((strlen("no one likes this") + 1), sizeof(char));
            strcpy(result, "no one likes this");
            break;

        case 1:
            result = (char*)calloc((strlen(" likes this") + strlen(names[0]) + 1), sizeof(char));
            sprintf(result, "%s likes this", names[0]);
            break;

        case 2:
            result = (char*)calloc((strlen(" and  like this") + strlen(names[0]) + strlen(names[1]) + 1), sizeof(char));
            sprintf(result, "%s and %s like this", names[0], names[1]);
            break;

        case 3:
            result = (char*)calloc((strlen(",  and  like this") + strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + 1), sizeof(char));
            sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
            break;

        default:
            asprintf(&count_as_str, "%d", n-2);
            result = (char*)calloc((strlen(",  and  others like this") + strlen(names[0]) + strlen(names[1]) + 1) + + strlen(count_as_str), sizeof(char));
            sprintf(result, "%s, %s and %s others like this", names[0], names[1], count_as_str);
            break;
    }
  return result;
}