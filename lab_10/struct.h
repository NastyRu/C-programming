#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define NO_MATCHES 1
#define FAILED 2

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

void insert(node_t **head, node_t *elem, node_t *before);

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

int comparator(const void *x1, const void *x2);

node_t *number_list(node_t *list, int n);

#endif  // STRUCT_H
