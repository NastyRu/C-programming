#include "my_string.h"

#define TESTS 11
#define FAILED 1

int test_strcmp(int *err_cnt)
{
    int err = 0;

    if (SUCCESS == my_strcmp("ADs fghF!", "ADs fghF!"))
        err++;

    if (NO_MATCHES == my_strcmp("aaaaaa", "aaaaaa a"))
        err++;

    if (NO_MATCHES == my_strcmp("aaaaaa", "aaaaba"))
        err++;

    if (3 == err)
    {
        (*err_cnt) += err;
        return SUCCESS;
    }

    printf("Failed test in strcmp function");
    return FAILED;
}

int test_getline(int *err_cnt)
{
    FILE *f = NULL;
    char *a = NULL;

    size_t n;
    int err = 0;

    if (ERR_GETLINE == my_getline(&a, &n, f))
        err++;
    free(a);

    f = fopen("in_1.txt", "r");
    if (ERR_GETLINE == my_getline(NULL, &n, f))
        err++;

    if (ERR_GETLINE == my_getline(&a, NULL, f))
        err++;
    if (NULL != a)
        free(a);

    n = 0;
    if (16 == my_getline(&a, &n, f) && SUCCESS == my_strcmp("aaaa a sss aa a\n", a))
        err++;
    free(a);
    fclose(f);

    f = fopen("in_2.txt", "r");
    n = 0;
    if (143 == my_getline(&a, &n, f) && SUCCESS == my_strcmp("asdfghjklkjhgfdsasdfghjklkjhgfds;kjhgfdfghjkl;loiuytrertyuiokjhgfdfghjklkjhgfdfghjklkjhgfdfghjkjhgfdfghjkjhgfdsdfghjkjhgfdsdfghjklkjhgfdsdfghj\n", a))
        err++;
    free(a);
    fclose(f);
    a = NULL;

    f = fopen("in_3.txt", "r");
    n = 0;
    if (ERR_GETLINE == my_getline(&a, &n, f))
        err++;
    fclose(f);

    (*err_cnt) += err;

    if (6 == err)
        return SUCCESS;

    printf("Failed test getline\n");
    return FAILED;
}

int test_str_replace(int *err_cnt)
{
    char *source = "aaaaabaaaabaababa";
    char *search = "aa";
    char *replace = "c";
    char *expect = "ccabccbcbaba";
    char *output;
    int err = 0;

    if (NULL == str_replace(NULL, NULL, NULL))
        err++;

    output = str_replace(source, search, replace);
    if (SUCCESS == my_strcmp(expect, output))
        err++;

    *(err_cnt) += err;

    free(output);

    if (2 == err)
        return SUCCESS;

    printf("Failed test str_replace\n");
    return FAILED;
}

int main()
{
    int err_cnt = 0;

    test_strcmp(&err_cnt);
    test_getline(&err_cnt);
    test_str_replace(&err_cnt);

    if (TESTS == err_cnt)
    {
        printf("SUCCESS");
        return SUCCESS;
    }
    else
        return FAILED;
}
