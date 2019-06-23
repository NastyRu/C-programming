#include <stdio.h>
#include <math.h>

#define INCORRECT_FILE -3
#define N 100

int read_array(FILE *f, int *arraymax, const int sizemax)
{
    int num;

    int kol = 0;

    while (fscanf(f, "%d ", &num) == 1 && kol++ < sizemax)
    {
        *arraymax = num;
        arraymax += 1;
    }

    if (0 == kol)
        return INCORRECT_FILE;

    if (kol < N)
        return kol;
    else
        return kol-1;
}
