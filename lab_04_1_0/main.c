/*
Сумма четных элементов массива
*/

#include <stdio.h>

#define N 10
#define INCORRECTED_DATA -1
#define NO_EVEN_NUMBERS -2

int input(int a[])
{
    int t;
    int n = 0;

    t = scanf("%d", &a[n]);

    while (t == 1)
    {
        n++;
        t = scanf("%d", &a[n]);
    }
    if (t && n <= N)
        return n;
    else
        return INCORRECTED_DATA;
}

int summ(const int a[], const int n, int *const kol)
{
    int i;
    int s = 0;

    for (i = 0; i < n; i++)
        if (0 == a[i]%2)
        {
            s += a[i];
            *kol += 1;
        }

    if (kol)
        return s;
    else
        return NO_EVEN_NUMBERS;
}

int main(void)
{
    int a[N];
    int n;
    int sum, kol = 0;

    n = input(a);

    if (n > 0)
        sum = summ(a, n, &kol);
    else
    {
        printf("Incorrected data");

        return INCORRECTED_DATA;
    }

    if (kol)
        printf("%d", sum);
    else
        printf("No even numbers");

    return 0;
}
