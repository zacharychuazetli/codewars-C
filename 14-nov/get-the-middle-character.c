#include <stdio.h>

char *get_middle(char outp[3], const char *inp);

int main()
{
    const char inp[] = "middle";
    char outp[3] = {'\0'};
    char *tmp = get_middle(outp, inp);
    printf("%s\n", outp);
    return 0;
}

char *get_middle(char outp[3], const char *inp)
{
    int len = 0;
    int middle = 0;
    while (inp[len] != '\0') {
        len++;
    }
    middle = len / 2;
    if (len % 2 != 0) {
        outp[0] = inp[middle];
        outp[1] = '\0';
    } else {
        outp[0] = inp[middle - 1];
        outp[1] = inp[middle];
        outp[2] = '\0';
    }

    return outp;
}