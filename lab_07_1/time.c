#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "work_with_file.h"
#include "bubble_sort.h"

#define MAX_N 1000000

int main(void)
{
    int array[MAX_N], copy_array[MAX_N];
    clock_t begin, end;

    srand(time(NULL));
    for (int i = 1; i <= MAX_N; i *= 10)
    {
        for (int j = 0; j < i; j++)
        {
            array[j] = rand();
            copy_array[j] = array[j];
        }
        begin = clock();
        mysort(array, i, sizeof(int), comparator);
        end = clock();

        printf("%d %f", i, (double)(end - begin) / CLOCKS_PER_SEC);

        begin = clock();
        qsort(copy_array, i, sizeof(int), comparator);
        end = clock();

        printf(" %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
    }
    return SUCCESS;
}
