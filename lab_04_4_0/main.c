/*
Сортировка пузырьком
*/

#include <stdio.h>
#include <math.h>

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

void sort(int a[], const int n)
{
    int i, j;
    int buf;

    for(i = 0 ; i < n-1; i++)
    {
        for(j = 0 ; j < n-i-1 ; j++)
        {
            if (a[j] > a[j+1])
            {
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
             }
        }
    }
}

void printarray(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int a[N];
    int n;

    n = input(a);

    if (n > 0)
    {
        sort(a, n);
        printarray(a, n);

        return TRUE;
    }
    else
    {
        printf("Incorrected data");

        return INCORRECTED_DATA;
    }
}
