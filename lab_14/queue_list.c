#include "queue_list.h"

struct queue_list *init_list(void)
{
    struct queue_list *lt = calloc(1, sizeof(struct queue_list));
    lt->size = 0;
    lt->begin = NULL;
    lt->end = NULL;
    return lt;
}

void push_list(struct queue_list *q, int data)
{
    struct list *node = calloc(1, sizeof(struct list));
    node->data = data;
    node->next = NULL;

    if(q->end != NULL)
        q->end->next = node;
    else
        q->begin = node;

    q->end = node;
    q->size += 1;
}

int pop_list(struct queue_list *q)
{
    if (q->size == 0)
        return NO_ELEMENTS;

    struct list *node = q->begin;
    int x = node->data;

    q->size -= 1;
    q->begin = node->next;
    free(node);

    if(q->size == 0)
    {
        q->begin = NULL;
        q->end = NULL;
    }
    return x;
}
