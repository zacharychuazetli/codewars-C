#include <stdio.h>

int persistence(int n);

int main() {
    int n = 25;
    int answer = persistence(n);
    printf("%d\n", answer);
    return 0;
}

int persistence(int n) {
    int digit = 0;
    int answer = 1;
    int count = 0;

    while (n >= 10) {
        while (n != 0) {
            digit = n % 10;
            answer = answer * digit;
            n = n / 10;
        }
        count++;
        if (answer < 10) {
            return count;
        } else {
            n = answer;
            answer = 1;
        }
    }
    return 0;
}