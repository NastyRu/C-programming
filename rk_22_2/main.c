#include "stepen.h"

#include <stdio.h>
#include <math.h>

#define N 100
#define INCORRECT -1
#define CORRECT 0

int main(int argc, char** argv)
{
    FILE *f;

    int n;
    int k;
    int a[N];
    int b[N];

    if (argc != 2)
    {
	printf("INCORRECT TYPE");
	return INCORRECT;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
	printf("NO FILE");
	return INCORRECT;
    }

    fscanf(f, "%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%d ", &a[i]) != 1)
	{
	    printf("INCORRECT TYPE");
	    return INCORRECT;
	}

	b[i] = a[i];
    }

    fscanf(f, "%d",&k);

    if (k < 1)
    {
	printf("INCORRECT DEGREE");
	return INCORRECT;
    }

    for (int i = 1; i < k; i++) 
        stepen(&n, b, a);

    fclose(f);

    printf("%d\n", n);

    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);

    return CORRECT;
}
