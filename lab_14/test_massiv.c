#include "queue_massiv.h"

#define TESTS 12
#define SUCCESS 0
#define FAILED 1

int test_push(int *err_cnt)
{
    int num = 0;

    struct queue_massiv q;
    init_massiv(&q);
    push_massiv(&q, 1);
    push_massiv(&q, 2);
    push_massiv(&q, 3);
    push_massiv(&q, 4);
    push_massiv(&q, 5);

    if (5 == q.size && 8 == q.init_size)
    {
        for (int i = 0; i < q.size; i++)
            if (q.data[i] == i + 1)
                num++;
        num++;
    }
    if (6 != num)
    {
        printf("Failed in push function");
        free(q.data);
        return FAILED;
    }

    (*err_cnt) += num;
    free(q.data);
    return SUCCESS;
}

int test_pop(int *err_cnt)
{
    int num = 0;

    struct queue_massiv q;
    init_massiv(&q);
    push_massiv(&q, 1);
    push_massiv(&q, 2);
    push_massiv(&q, 3);
    push_massiv(&q, 4);
    push_massiv(&q, 5);

    if (1 == pop_massiv(&q))
        num++;
    if (2 == pop_massiv(&q))
        num++;
    if (3 == pop_massiv(&q))
        num++;
    if (4 == pop_massiv(&q))
        num++;
    if (5 == pop_massiv(&q))
        num++;
    if (NO_ELEMENTS == pop_massiv(&q))
        num++;

    if (6 != num)
    {
        printf("Failed in pop function");
        return FAILED;
    }

    (*err_cnt) += num;
    return SUCCESS;
}

int main()
{
    int err_cnt = 0;

    test_pop(&err_cnt);
    test_push(&err_cnt);

    if (TESTS == err_cnt)
    {
        printf("SUCCESS");
        return SUCCESS;
    }

    return FAILED;
}
