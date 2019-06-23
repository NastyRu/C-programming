#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "filter.h"
#include "work_with_file.h"
#include "test_filter.h"

#define CORRECT 0
#define INCORRECT 1
#define FAILED 2
#define N 5

int mistake_f(int *min, int *end, int kol, int num_test)
{
    for (int i = 0; i < kol; i++)
        if (end[i] != min[i])
        {
            printf("Mistake in test%d\n", num_test);
            free(min);
            return INCORRECT;
        }

    free(min);

    return CORRECT;
}

int test_filter1(int *err_cnt)
{
    int array[N] = { 0, 1, 2, 3, 4 };
    int end[3] = { 1, 2, 3 };
    int *max, *min;

    key(array, array + N, &min, &max);

    if (CORRECT == mistake_f(min, end, 3, 1))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_filter2(int *err_cnt)
{
    int array[N] = { 0, 1, 3, 2, 1 };
    int end[1] = { 1 };
    int *max, *min;

    key(array, array + N, &min, &max);

    if (CORRECT == mistake_f(min, end, 1, 2))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_filter3(int *err_cnt)
{
    int array[N] = { 1, 2, 2, 1, 3 };
    int end[3] = { 2, 2, 1 };
    int *max, *min;

    key(array, array + N, &min, &max);

    if (CORRECT == mistake_f(min, end, 3, 3))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_filter(void)
{
    int err_cnt = 0;

    test_filter1(&err_cnt);
    test_filter2(&err_cnt);
    test_filter3(&err_cnt);

    if (3 == err_cnt)
        return SUCCESS;

    return FAILED;
}
