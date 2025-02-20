#include <stdio.h>

int solution(int number);

int main()
{
    int number = 10;
    int result = solution(number);
    printf("Result: %d\n", result);

    return 0;
}


int solution(int number) 
{
    int sum = 0;
    int initial_num = 0;
    while (initial_num < number)
    {
        if (((initial_num % 3) == 0) || ((initial_num % 5) == 0))
        {
            sum = sum + initial_num;
        }
        initial_num += 1;
    }
    return sum;
}