/*
Вычислить значение max(x[0] + x[n-1], x[1] + x[n-2], x[2] + x[n-3], ..., x[(n-1)/2] + x[n/2])
*/

#include <stdio.h>
#include <math.h>

#include "read_array.h"
#include "max.h"

#define TRUE 0
#define INCORRECT_FORM -1
#define NO_FILE -2
#define INCORRECT_FILE -3
#define BIG_ARRAY -4
#define N 100

int main(int argc, char** argv)
{
    FILE *f;

    int array[N];
    const int *array1 = array;
    int *arraymax = array;

    int k;

    if (argc != 2)
    {
        printf("Incorrected form\nCorrect form: ./main.exe <file-name>");
        return INCORRECT_FORM;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("No file");
        return NO_FILE;
    }

    k = read_array(f, arraymax, N);

    if (k >= 0)
    {
        arraymax = arraymax + k;

        printf("%d", max(array1,arraymax));
    }

    if (k == INCORRECT_FILE)
        printf("Incorrect file");

    fclose(f);

    if (k < 0)
        return k;
    else if (N == k)
        return BIG_ARRAY;
    else
        return TRUE;
}
