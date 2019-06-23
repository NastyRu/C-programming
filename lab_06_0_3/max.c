#include "max.h"

int max(const int *array1, const int * const arraymax)
{
    int n = 1;
    int maxim = *array1 + *(arraymax-1);

    while(array1 < arraymax)
    {
        if (*array1 + *(arraymax-n) > maxim)
            maxim = *array1 + *(arraymax-n);
        array1++;
        n++;
    }

    return maxim;
}
