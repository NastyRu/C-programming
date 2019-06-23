#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "work_with_file.h"
#include "action_with_matrix.h"

void rand_matr(int n)
{
    FILE *f = fopen("rand_matrix.txt", "w");

    fprintf(f, "%d %d %d\n", n, n, n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(f, "%d %d %d\n", i + 1, j + 1, -100 + rand() % 100);
        }
    }
    fclose(f);
}

int main()
{
    rand_matr(100);

    return SUCCESS;
}
