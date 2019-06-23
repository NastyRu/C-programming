#include "string.h"

#define TESTS 8

int test_negative(int *err_cnt)
{
    char str[100];
    int n1 = 0, n2 = 0;

    n1 = my_snprintf(str, 10, "%d\n", -10);
    n2 = snprintf(str, 10, "%d\n", -10);

    if (n1 == n2)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed negative tests\n");
    return FAILED;
}

int test_d(int *err_cnt)
{
    char str[100];
    int n1 = 0, n2 = 0;

    n1 = my_snprintf(str, 10, "%d\n", 10);
    n2 = snprintf(str, 10, "%d\n", 10);

    if (n1 == n2)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed int tests\n");
    return FAILED;
}

int test_ld(int *err_cnt)
{
    char str[100];
    int n1 = 0;

    n1 = my_snprintf(str, 10, "%ld\n", 1123456781234567890);

    if (n1 == 20)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed long int tests\n");
    return FAILED;
}

int test_c(int *err_cnt)
{
    char str[100];
    int n1 = 0, n2 = 0;

    n1 = my_snprintf(str, 10, "%c\n", 'c');
    n2 = snprintf(str, 10, "%c\n", 'c');

    if (n1 == n2)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed char tests\n");
    return FAILED;
}

int test_o(int *err_cnt)
{
    char str[100];
    int n1 = 0, n2 = 0;

    n1 = my_snprintf(str, 10, "%o\n", 0123);
    n2 = snprintf(str, 10, "%o\n", 0123);

    if (n1 == n2)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed octal tests\n");
    return FAILED;
}

int test_lo(int *err_cnt)
{
    char str[100];
    int n1 = 0;

    n1 = my_snprintf(str, 10, "%ld\n", 011234542525243567123);

    if (n1 == 19)
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed long octal tests\n");
    return FAILED;
}

int test_null(int *err_cnt)
{
    if (3 == my_snprintf(NULL, 10, "%d", 123))
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed null tests\n");
    return FAILED;
}

int test_incorrect(int *err_cnt)
{
    char str[100];

    if (-1 == my_snprintf(str, 10, "%e", 'c') && -1 == my_snprintf(str, 10, "%le", 'c'))
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("Failed incorrect tests\n");
    return FAILED;
}

int main()
{
    int err_cnt = 0;

    test_c(&err_cnt);
    test_d(&err_cnt);;
    test_o(&err_cnt);
    test_negative(&err_cnt);
    test_incorrect(&err_cnt);
    test_ld(&err_cnt);
    test_lo(&err_cnt);
    test_null(&err_cnt);

    if (TESTS == err_cnt)
    {
        printf("SUCCESS");
        return SUCCESS;
    }

    return FAILED;
}
