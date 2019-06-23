#ifndef QUEUE_MASSIV_H
#define QUEUE_MASSIV_H

#include <stdio.h>
#include <stdlib.h>
#define NO_ELEMENTS -1

struct queue_massiv {
  int *data;
  int size;
  int init_size;
};

void init_massiv(struct queue_massiv *q);
void push_massiv(struct queue_massiv *q, int x);
int pop_massiv(struct queue_massiv *q);

#endif // QUEUE_MASSIV_H
