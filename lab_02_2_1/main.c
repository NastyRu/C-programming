/*
Вычисление n-ого числа ряда Фибоначчи.
*/

#include <stdio.h>

int scanf(const char * restrict format, ...);

int fibonachi(int n)
{
    if (0 == n)
        return 0;
    else if (1 == n)
        return 1;
    else
        return fibonachi(n-1)+fibonachi(n-2);
}

int main()
{
    int num;
    int vvod;

    printf("Enter number ");

    vvod = scanf("%d", &num);
    if (1 == vvod)
        printf("Fibonachi %d number is %d ", num, fibonachi(num));
    else
        printf("Input error\n");

    return 0;

}
