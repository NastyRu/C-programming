#include "queue_list.h"

#define TESTS 12
#define SUCCESS 0
#define FAILED 1

void free_list(struct list *list)
{
    while (list != NULL)
    {
        struct list *copy = list->next;
        free(list);
        list = copy;
    }
}

int test_push(int *err_cnt)
{
    int num = 0;
    struct queue_list *q = init_list();

    push_list(q, 1);
    push_list(q, 2);
    push_list(q, 3);
    push_list(q, 4);
    push_list(q, 5);

    struct queue_list *copy = q;
    if (5 == q->size)
    {
        int i = 1;
        while (copy->begin != NULL)
        {
            if (copy->begin->data == i)
                num++;
            copy->begin = copy->begin->next;
            i++;
        }
        num++;
    }
    if (6 != num)
    {
        printf("Failed in push function");
        free_list(q->begin);
        return FAILED;
    }

    (*err_cnt) += num;
    free_list(q->begin);
    return SUCCESS;
}

int test_pop(int *err_cnt)
{
    int num = 0;
    struct queue_list *q = init_list();

    push_list(q, 1);
    push_list(q, 2);
    push_list(q, 3);
    push_list(q, 4);
    push_list(q, 5);

    if (1 == pop_list(q))
        num++;
    if (2 == pop_list(q))
        num++;
    if (3 == pop_list(q))
        num++;
    if (4 == pop_list(q))
        num++;
    if (5 == pop_list(q))
        num++;
    if (NO_ELEMENTS == pop_list(q))
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
