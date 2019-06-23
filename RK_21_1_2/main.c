/* Задача 2. Вариант 1.
Определить в последовательности числа являющиеся числами Фибоначчи.
Вывести максимальное найденное.
*/

#include <stdio.h>

int fibonachi(int max,int a)
{
    int x1 = 1, x2 = 1, t;

    while (x2 < a)
    {
        t = x2;
        x2 = x1 + x2;
        x1 = t;
    }
    if (x2 == a)
        if (x2 > max)
            max = x2;

    return max;
}

int main(void)
{
    int a = 1, max = 0;

    while (a != 0)
    {
        scanf("%d",&a);
        max = fibonachi(max,a);
    }

    if (max != 0)
        printf("%d", max);
    else
        printf("No fibonachi");

    return 0;
}
