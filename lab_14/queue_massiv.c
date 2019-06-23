#include "queue_massiv.h"

void init_massiv(struct queue_massiv *q)
{
    q->data = calloc(2, sizeof(int));
    q->size = 0;
    q->init_size = 2;
}

void push_massiv(struct queue_massiv *q, int x)
{
    if (q->size == q->init_size)
    {
        q->init_size *= 2;
        q->data = realloc(q->data, q->init_size);
    }
    q->data[q->size] = x;
    (q->size)++;
}

int pop_massiv(struct queue_massiv *q)
{
    int x;
    if (0 == q->size)
        return NO_ELEMENTS;
    x = q->data[0];

    for (int i = 0; i < q->size - 1; i++)
        q->data[i] = q->data[i + 1];
    (q->size)--;
    return x;
}
