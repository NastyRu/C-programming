#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "bubble_sort.h"
#include "work_with_file.h"
#include "test_buble_sort.h"

#define CORRECT 0
#define INCORRECT 1
#define FAILED 2
#define N 5

#define MAX_KOL 1000

void generation(int *array, int *end)
{
    for (int i = 0; i < MAX_KOL; i++)
    {
        array[i] = MAX_KOL / 2 - i;
        end[i] = i - MAX_KOL / 2 + 1;
    }
}

int mistake_sort(int *array, int *end, int kol, int num_test)
{
    for (int i = 0; i < kol; i++)
        if (end[i] != array[i])
        {
            printf("Mistake in test%d\n", num_test);
            return INCORRECT;
        }

    return CORRECT;
}

int test_bubble_sort5(int *err_cnt)
{
    int array[MAX_KOL];
    int end[MAX_KOL];
    generation(array, end);

    mysort(array, MAX_KOL, sizeof(int), comparator);

    if (CORRECT == mistake_sort(array, end, MAX_KOL, 5))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_bubble_sort1(int *err_cnt)
{
    int array[N] = { 0, 1, 2, 3, 4 };
    int end[N] = { 0, 1, 2, 3, 4 };

    mysort(array, N, sizeof(int), comparator);

    if (CORRECT == mistake_sort(array, end, N, 1))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_bubble_sort2(int *err_cnt)
{
    int array[N] = { 1, 1, 1, 1, 1 };
    int end[N] = { 1, 1, 1, 1, 1 };

    mysort(array, N, sizeof(int), comparator);

    if (CORRECT == mistake_sort(array, end, N, 2))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_bubble_sort3(int *err_cnt)
{
    int array[N] = { 0, 1, 3, 2, 1 };
    int end[N] = { 0, 1, 1, 2, 3 };

    mysort(array, N, sizeof(int), comparator);

    if (CORRECT == mistake_sort(array, end, N, 3))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_bubble_sort4(int *err_cnt)
{
    int array[N] = { 4, 3, 2, 1, 0 };
    int end[N] = { 0, 1, 2, 3, 4 };

    mysort(array, N, sizeof(int), comparator);

    if (CORRECT == mistake_sort(array, end, N, 4))
    {
        (*err_cnt)++;

        return CORRECT;
    }

    return INCORRECT;
}

int test_bubble_sort(void)
{
    int err_cnt = 0;

    test_bubble_sort1(&err_cnt);
    test_bubble_sort2(&err_cnt);
    test_bubble_sort3(&err_cnt);
    test_bubble_sort4(&err_cnt);
    test_bubble_sort5(&err_cnt);

    if (5 == err_cnt)
        return SUCCESS;

    return FAILED;
}
