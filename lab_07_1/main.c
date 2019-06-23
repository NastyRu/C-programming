#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "work_with_file.h"
#include "filter.h"
#include "bubble_sort.h"

int main(int argc, char **argv)
{
    FILE *f = NULL;
    int kol = 0;
    int *array = NULL, *new_array = NULL;
    int *arrayn, *array1;
    int *arraymin, *arraymax;

    if (argc < 3 || argc > 4)
    {
        printf("Incorrected form\nCorrect form: ./main.exe <file-name> <file-name> f");
        return INCORRECT_FORM;
    }

    if (SUCCESS == read_kol(f, argv[1], &kol))
    {
        array = calloc(kol, sizeof(int));
        arrayn = array1 = array;

        if (SUCCESS != read_array(f, argv[1], &arrayn))
        {
            printf("Incorrect work with file");
            free(array);
            return INCORRECT_WORK_WITH_FILE;
        }

        if (kol != (arrayn - array1))
        {
            printf("Incorrect file");
            return INCORRECT_FILE;
        }
    }
    else
        return INCORRECT_FILE;

    if (array == NULL)
    {
        printf("Incorrect file");
        return INCORRECT_FILE;
    }

    if (4 == argc && 0 == strcmp(argv[3], "f"))
    {
        arraymax = new_array;

        if (SUCCESS != key(array1, arrayn, &new_array, &arraymax))
        {
            free(array);
            return INCORRECT_FILE;
        }

        arraymin = new_array;

        mysort(new_array, labs(arraymin - arraymax), sizeof(int), comparator);
        write_in_file(f, argv[2], new_array, labs(arraymin - arraymax));

        free(new_array);
    }
    else if (3 == argc)
    {
        mysort(array, kol, sizeof(int), comparator);
        write_in_file(f, argv[2], array, kol);
    }
    else
    {
        free(array);
        printf("Incorrected form\nCorrect form: ./main.exe <file-name> <file-name> f");
        return INCORRECT_FORM;
    }

    free(array);
    return SUCCESS;
}
