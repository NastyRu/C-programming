/*
Создавать на основе исходного новый массив, элементы которого
больше среднего арифметического данного
*/

#include <stdio.h>

#define N 10
#define INCORRECTED_DATA -1
#define TRUE 0

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

float sum(const int a[], const int n)
{
    int i;
    int s = 0;

    for (i = 0; i < n; i++)
        s += a[i];

    return (float) s/n;
}

int new(float s, const int a[], const int na, int b[])
{
    int i;
    int nb = 0;

    for (i = 0; i < na; i++)
        if (a[i] > s)
        {
            b[nb] = a[i];
            nb++;
        }

    return nb;
}

int printarray(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return TRUE;
}

int main(void)
{
    int a[N], b[N];
    int na = 0, nb = 0;
    float even;

    na = input(a);

    if (na > 0)
        even = sum(a, na);
    else
    {
        printf("Incorrected data");

        return INCORRECTED_DATA;
    }

    nb = new(even, a, na, b);

    if (nb > 0)
        printarray(b, nb);
    else
        printf("Empty array");

    return TRUE;
}
