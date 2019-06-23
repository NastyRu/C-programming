#include <stdio.h>
#include <math.h>

#define N 10
#define INCORRECTED_DATA -1
#define NO_PALLINDROM -2
#define OVERSTEP -3
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

int pallindrom(int x)
{
    int x1 = x, x2;
    int n = 0;

    while (x1 > 0)
    {
        n++;
        x1 = x1/10;
    }

    n--;

    while (x > 0)
    {
        x2 = x/pow(10, n);

        if (x2 == x%10)
            x = x2/10;
        else
            return NO_PALLINDROM;

        n = n-2;
    }

    return TRUE;
}

int delete(int a[], int *const n, const int i)
{
    int j;

    if (a[*(n-1)])
    {
        for (j = i; j < (*n-1); j++)
            a[j] = a[j+1];

        a[*n-1] = 0;
        *n = *n-1;

        return TRUE;
    }
    else
        return OVERSTEP;
}

void deletepallindrom(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
        if (0 == pallindrom(a[i]) && a[i] >= 0)
        {
            delete(a, n, i);
            i--;
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
        deletepallindrom(a, &n);

        if (n > 0)
            printarray(a, n);
        else
            printf("Empty array");

        return TRUE;
    }
    else
    {
        printf("Incorrected data");

        return INCORRECTED_DATA;
    }
}
