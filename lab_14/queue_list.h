#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#define NO_ELEMENTS -1

struct list {
    struct list *next;
    int data;
};

struct queue_list {
    int size;
    struct list *begin, *end;
};

struct queue_list *init_list(void);
void push_list(struct queue_list *q, int data);
int pop_list(struct queue_list *q);

#endif // QUEUE_LIST_H
