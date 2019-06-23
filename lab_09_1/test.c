#include "function.h"

#define SUCCESS 0
#define FAILED 1

int comparison(char *a, char *b, int *err_cnt)
{
    int i = 0;
    while (b[i] != '\0' && a[i] != '\0')
    {
        if (a[i] != b[i])
        {
            printf("FAILED\n");
            return FAILED;
        }
        i++;
    }
    if (a[i] == b[i])
    {
        (*err_cnt)++;
        return SUCCESS;
    }

    printf("FAILED\n");
    return FAILED;
}

void test1(int *err_cnt)
{
    char *a = "abcdefgh";
    char *b = "abcdefgh";
    int n = 20;

    a = my_strndup(a, n);
    comparison(a, b, err_cnt);
    free(a);
}

void test2(int *err_cnt)
{
    char *a = "abcdefgh";
    char *b = "abcde";
    int n = 5;

    a = my_strndup(a, n);
    comparison(a, b, err_cnt);
    free(a);
}

void test3(int *err_cnt)
{
    char *a = "a";
    char *b = "";
    int n = 0;

    a = my_strndup(a, n);
    comparison(a, b, err_cnt);
    free(a);
}
int main()
{
    int err_cnt = 0;
    test1(&err_cnt);
    test2(&err_cnt);
    test3(&err_cnt);

    if (3 == err_cnt)
    {
        printf("SUCCESS\n");
        return SUCCESS;
    }
    return FAILED;
}
