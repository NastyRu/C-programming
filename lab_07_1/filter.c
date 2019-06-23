#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "filter.h"
#include "work_with_file.h"

/*
Выполняется проход по массиву и создается новый массив по заданному фильтру
оставляем элементы между макисмальным и минимальным, они в массив не входят

@param pb_src [in]
@param pe_src [in]
@param pb_dst [out]
@param pe_dst [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int min, max;
    int *amin, *amax, *begin;
    int kol;
    int i = 0;

    if (pb_src == pe_src || NULL == pb_src || NULL == pe_src)
        return INCORRECT_FORM;

    min = max = *pb_src;
    amin = amax = (int*)pb_src;

    while (pb_src < pe_src)
    {
        if (*pb_src < min)
        {
            amin = (int*)pb_src;
            min = *pb_src;
        }
        if (*pb_src > max)
        {
            amax = (int*)pb_src;
            max = *pb_src;
        }

        pb_src++;
    }

    if (labs(amax - amin) < 2)
    {
        printf("No elements");

        return NO_ELEMENTS;
    }

    kol = labs(amin - amax) - 1;

    *pb_dst = calloc(kol, sizeof(int));

    if (NULL == pb_dst)
    {
        printf("Not allocate memory");

        return NO_MEMORY;
    }

    if (amin < amax)
        begin = amin;
    else
        begin = amax;

    begin++;

    while (i < kol)
    {
        (*(*pb_dst + i)) = *begin;
        i++;
        begin++;
    }

    *pe_dst = *pb_dst + kol;

    return SUCCESS;
}
