#include <stdio.h>
#include <stdint.h>

char *create_phone_number(char phnum[15], const uint8_t digits[10]);

int main()
{
    const uint8_t digits[]= {0,1,2,3,4,5,6,7,8,9};
    char phnum[15];
    char *temp = create_phone_number(phnum, digits);
    printf("%s", phnum);
    return 0;
}

char *create_phone_number(char phnum[15], const uint8_t digits[10])
{
    // write to phnum and return it
    // it must be nul-terminated
    char tmp1[4] = {'\0'};
    char tmp2[4] = {'\0'};
    char tmp3[5] = {'\0'};
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < 10; i++) {
        if (i < 3) {
            sprintf(tmp1 + count1, "%d", digits[i]);
            count1++;
        } else if (i >= 3 && i < 6) {
            sprintf(tmp2 + count2, "%d", digits[i]);
            count2++;
        } else if (i >= 6 && i < 10) {
            sprintf(tmp3 + count3, "%d", digits[i]);
            count3++;
        }
    }
    // sprintf will remove any unecessasry null terminators and put one at the end only
    sprintf(phnum, "(%s) %s-%s", tmp1, tmp2, tmp3);
    return phnum;
}