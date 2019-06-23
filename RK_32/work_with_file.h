#ifndef _WORK_WITH_FILE_H
#define _WORK_WITH_FILE_H

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#define INCORRECT_FORM 1
#define SUCCESS 0

struct temp {
    struct list_head list;
    int day;
    int month;
    int year;
    int min;
    int max;
};
struct sr_znac {
    int year;
    int month;
    double data;
    struct sr_znac *next;
};

void insert(struct sr_znac **head, struct sr_znac *elem, struct sr_znac *before);
struct sr_znac *add_in_end(struct sr_znac *head, struct sr_znac *data);
void sorted_insert(struct sr_znac **head, struct sr_znac *element, int (*comparator)(double, double));
void free_list_temp(struct sr_znac *list);
void print_list(struct sr_znac *list);
struct sr_znac *sort(struct sr_znac *head, int (*comparator)(int, int));

void read_from_file(struct temp *temp, const char *filename);
void free_list(struct temp *temp);
void table_temp(struct temp *temp);

#endif //  _WORK_WITH_FILE_H
