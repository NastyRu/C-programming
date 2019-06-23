#ifndef _WORK_WITH_TABLE_H
#define _WORK_WITH_TABLE_H

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

void read_from_file(struct temp *temp, const char *filename, int *min_year, int *max_year);
void write_to_file(struct temp *temp, const char *filename, int min_year, int max_year);
void free_list(struct temp *temp);

#endif //  _WORK_WITH_TABLE_H
