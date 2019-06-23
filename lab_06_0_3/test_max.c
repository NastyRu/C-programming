#include <stdio.h>

#include "max.h"

#define CORRECT 0
#define INCORRECT -1

int test1(int *err_cnt)
{
    int a[] = {1, 2, 3, 4, 5};

    if (max(&a[0], &a[5]) != 6)
    {
        (*err_cnt)++;
        printf("Failed test\n");
        printf("Array [1,2,3,4,5]\n");
        printf("Expected 6\n");
        printf("Received %d", max(&a[0], &a[5]));

        return INCORRECT;
    }
    return CORRECT;
}

int test2(int *err_cnt)
{
    int a[] = {3, 0, 0, 4};

    if (max(&a[0], &a[4]) != 7)
    {
        (*err_cnt)++;
        printf("Failed test\n");
        printf("Array [3,0,0,4]\n");
        printf("Expected 7\n");
        printf("Received %d", max(&a[0], &a[4]));

        return INCORRECT;
    }
    return CORRECT;
}

int test3(int *err_cnt)
{
    int a[] = {0, 3, 4, 0};

    if (max(&a[0], &a[4]) != 7)
    {
        (*err_cnt)++;
        printf("Failed test\n");
        printf("Array [0,3,4,0]\n");
        printf("Expected 7\n");
        printf("Received %d", max(&a[0], &a[4]));

        return INCORRECT;
    }
    return CORRECT;
}
void test_max(void)
{
    int err_cnt = 0;

    test1(&err_cnt);

    test2(&err_cnt);

    test3(&err_cnt);

    if (0 == err_cnt)
        printf("OK");
    else
    printf("FAILED");
}

int main(void)
{
    test_max();

    return 0;
}
