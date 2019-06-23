#include <stdio.h>

#include "read_array.h"

#define INCORRECT -1
#define CORRECT 0

#define INCORRECT_FILE -3
#define N 100

int test1(int *err_cnt)
{
    FILE *f;

    int a[100];
    int *arraymax = a;

    f = fopen("in_1.txt", "r");

    if (read_array(f, arraymax, N) != INCORRECT_FILE)
    {
        printf("Failed test\n");
        printf("in_1.txt\n");
        printf("Expected -3\n");
        printf("Received %d", read_array(f, arraymax, N));
        (*err_cnt)++;

        return INCORRECT;
    }
    fclose(f);

    return CORRECT;
}

int test2(int *err_cnt)
{
    FILE *f;

    int a[100];
    int *arraymax = a;

    f = fopen("in_2.txt", "r");

    if (read_array(f, arraymax, N) != 100)
    {
        printf("Failed test\n");
        printf("in_2.txt\n");
        printf("Expected 100\n");
        printf("Recieved %d", read_array(f, arraymax, N));
        (*err_cnt)++;

        return INCORRECT;
    }
    fclose(f);

    return CORRECT;
}

int test3(int *err_cnt)
{
    FILE *f;

    int a[100];
    int *arraymax = a;

    f = fopen("in_3.txt", "r");

    if (read_array(f, arraymax, N) != 5)
    {
        printf("Failed test\n");
        printf("in_3.txt\n");
        printf("Expected 5\n");
        printf("Recieved %d", read_array(f, arraymax, N));
        (*err_cnt)++;

        return INCORRECT;
    }
    fclose(f);

    return CORRECT;
}

void test_read_array(void)
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
    test_read_array();

    return 0;
}
