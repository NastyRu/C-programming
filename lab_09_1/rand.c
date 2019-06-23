#include "function.h"
#include <string.h>
#include <time.h>

#define N 10000000

int main()
{
    char *a = NULL, *b = NULL, *c = NULL;
    clock_t begin, end;
    FILE *f = fopen("rand.txt", "w");

    for (int i = 1; i < N; i += 1000)
    {
        a = calloc(i + 1, sizeof(char));
        for (int j = 0; j < i; j++)
            a[j] = 'a';

        fprintf(f, "%d  ", i);

        begin = clock();
        b = strndup(a, i);
        end = clock();
        fprintf(f, "%lu  ", end - begin);

        begin = clock();
        c = my_strndup(b, i);
        end = clock();
        fprintf(f, "%lu  \n", end - begin);

        free(a);
        free(b);
        free(c);
    }
}
