#include "stepen.h"

#include <stdio.h>
#include <math.h>

void stepen(const int *n, int b[], const int a[])
{
    int size = sqrt(*n);
    int c[*n];

    for (int i = 0; i < *n; i++)
	c[i] = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
	{
	    for (int k = 0; k < size; k++)
	    {
		c[i*size + j] += b[i*size + k]*a[k*size + j];
	    }
	}
    }

    for (int i = 0; i < *n; i++)
    {
	b[i] = c[i];
    }
}
