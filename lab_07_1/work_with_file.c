#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "work_with_file.h"

/*
Выполняется проход по файлу, проверка элементов и подсчет их количества

@param f [in]
@param kol [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int read_kol(FILE *f, const char *argv, int *kol)
{
    int num;

    f = fopen(argv, "r");

    if (f == NULL)
    {
        printf("No file");

        return NO_FILE;
    }

    while (0 == feof(f))
    {
        if (1 == fscanf(f, "%d ", &num))
            (*kol)++;
        else
        {
            fclose(f);

            printf("Incorrect file");

            return INCORRECT_FILE;
        }
    }

    if (EOF == fclose(f))
    {
        printf("Can not close file");
        return INCORRECT_WORK_WITH_FILE;
    }

    return SUCCESS;
}

/*
Выполняется проход по файлу, проверка элементов и считывание их в массив

@param f [in]
@param arrayn [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int read_array(FILE *f, const char *argv, int **arrayn)
{
    int num;

    f = fopen(argv, "r");

    if (f == NULL)
    {
        printf("No file");

        return NO_FILE;
    }

    if (NULL == arrayn)
    {
        printf("Not allocate memory");

        if (EOF == fclose(f))
        {
            return INCORRECT_WORK_WITH_FILE;
        }

        return NO_MEMORY;
    }

    while (0 == feof(f))
    {
        if (1 == fscanf(f, "%d ", &num))
        {
            (**arrayn) = num;
            (*arrayn) += 1;
        }
    }

    if (EOF == fclose(f))
    {
        printf("Can not close file");
        return INCORRECT_WORK_WITH_FILE;
    }

    return SUCCESS;
}

/*
Выполняется запись массива в файл

@param f [out]
@param kol [in]
@param array [in]
*/
void write_in_file(FILE *f, const char *argv, int *array, int kol)
{
    f = fopen(argv, "w");

    for (int i = 0; i < kol; i++)
        fprintf(f, "%d ", *(array + i));

    fclose(f);
}
