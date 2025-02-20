#include <stdio.h>
#include <stdlib.h>

void high_and_low (const char *strnum, char *result);

int main()
{
    const char strnum[] = "1 2 -3 4 1 -32";
    char result[sizeof(strnum)] = {'\0'};
    high_and_low(strnum, result);
    printf("%s", result);
}

void high_and_low (const char *strnum, char *result)
{
    // print your answer to <result> :
    int highest = 0;
    int lowest = 0;
    int num = 0;
    const char *ptr = strnum;
    while (sscanf(ptr, "%d", &num) == 1) {
        if (highest == 0 && lowest == 0) {
            highest = num;
            lowest = num;
        }
        if (num > highest) {
            highest = num;   
        }
        if (num < lowest) {
            lowest = num;
        }
        while (*ptr != '\0' && *ptr != ' ') {
            ptr++;
        }
        while (*ptr == ' ') {
            ptr++;
        }
    }

    sprintf(result, "%d %d", highest, lowest);
}