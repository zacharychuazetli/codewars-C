#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool narcissistic(int num);

int main() {
    int num = 153;
    bool answer = narcissistic(num);
    printf("%d\n", answer);
    return 0;
}

bool narcissistic(int num)
{
    int digit = 0; int count = 0; int sum = 0;
    int inter = num;

    while (inter != 0){
        count++;
        inter = inter / 10;
    }
    inter = num;
    while (inter != 0){
        digit = inter % 10;
        sum = sum + pow(digit, count);
        inter = inter / 10;
    }
    if (sum == num) {
        return true;
    } else {
        return false;
    }
}