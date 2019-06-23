#include "work_with_file.h"

int double_comparator(double x1, double x2)
{
    return x1 - x2;
}
int int_comparator(int x1, int x2)
{
    return x1 - x2;
}

void insert(struct sr_znac **head, struct sr_znac *elem, struct sr_znac *before)
{
    if (NULL == head || NULL == (*head) || NULL == elem || NULL == before)
        return;
    struct sr_znac *buffer = (*head);

    if (buffer == before)
    {
        (*head) = elem;
        (*head)->next = before;
        return;
    }
    while (buffer->next != before)
    {
        buffer = buffer->next;
        if (NULL == buffer)
            return;
    }
    buffer->next = elem;
    buffer = buffer->next;
    buffer->next = before;
}

struct sr_znac *add_in_end(struct sr_znac *head, struct sr_znac *data)
{
    struct sr_znac *buf = head;

    if (!head)
    {
        data->next = NULL;
        return data;
    }
    for (; buf->next; buf = buf->next);
    buf->next = data;
    buf = buf->next;
    buf->next = NULL;
    return head;
}

void sorted_insert(struct sr_znac **head, struct sr_znac *element, int (*comparator)(double, double))
{
    struct sr_znac *buf = (*head);
    element->next = NULL;

    while (buf != NULL && comparator(buf->data, element->data) < 0)
        buf = buf->next;
    if (buf != NULL)
    {
        insert(head, element, buf);
    }
    else
    {
        (*head) = add_in_end(*head, element);
    }
}

void free_list_temp(struct sr_znac *list)
{
    while (list != NULL)
    {
        struct sr_znac *copy = list->next;
        free(list);
        list = copy;
    }
}

void print_list(struct sr_znac *list)
{
    while (list != NULL)
    {
        printf("%d %d %f\n", list->year, list->month, list->data);
        list = list->next;
    }
}

void sorted_insert_year(struct sr_znac **head, struct sr_znac *element, int (*comparator)(int, int))
{
    struct sr_znac *buf = (*head);
    element->next = NULL;

    while (buf != NULL && comparator(buf->year, element->year) < 0)
        buf = buf->next;
    if (buf != NULL)
    {
        insert(head, element, buf);
    }
    else
    {
        (*head) = add_in_end(*head, element);
    }
}

struct sr_znac *sort(struct sr_znac *head, int (*comparator)(int, int))
{
    struct sr_znac *sorted = NULL;
    int  i = 0;

    while (head != NULL)
    {
        struct sr_znac *buffer = head;
        head = head->next;
        sorted_insert_year(&sorted, buffer, comparator);
        i++;
    }
    return sorted;
}


void read_from_file(struct temp *temp, const char *filename)
{
    struct temp *buf;
    FILE *f = fopen(filename, "r");

    while(!feof(f))
    {
        buf = (struct temp *)calloc(1, sizeof(struct temp));
        fscanf(f, "%d %d %d %d %d\n", &buf->year, &buf->month, &buf->day, &buf->max, &buf->min);
        list_add(&(buf->list), &(temp->list));
    }
    fclose(f);
}

void free_list(struct temp *temp)
{
    struct list_head *beg, *beg_buf;
    struct temp *buf;
    list_for_each_safe(beg, beg_buf, &temp->list)
    {
         buf = list_entry(beg, struct temp, list);
         list_del(beg);
         free(buf);
    }
}

void table_temp(struct temp *temp)
{
    struct list_head *beg;
    struct temp *buf;
    struct sr_znac *temp_sr = NULL;
    int now_month = 0, kol_day = 0, last_month = 1;
    double sr_znac = 0;

    list_for_each(beg, &(temp->list))
    {
        buf = list_entry(beg, struct temp, list);
        now_month = buf->month;
        if (now_month == last_month)
        {
            sr_znac += buf->max;
            kol_day++;
        }
        else
        {
            if (kol_day != 0)
                sr_znac = sr_znac / kol_day;
            else
                sr_znac = 0;
            if (NULL == temp)
            {
                temp_sr = calloc(1, sizeof(struct sr_znac));
                temp_sr->year = buf->year;
                temp_sr->month = last_month;
                temp_sr->data = sr_znac;
                temp_sr->next = NULL;
            }
            else
            {
                struct sr_znac *pers = calloc(1, sizeof(struct sr_znac));
                pers->year = buf->year;
                pers->month = last_month;
                pers->data = sr_znac;
                pers->next = NULL;
                sorted_insert(&temp_sr, pers, double_comparator);
            }
            sr_znac = 0;
            kol_day = 0;
        }
        last_month = buf->month;
    }
    temp_sr = sort(temp_sr, int_comparator);
    print_list(temp_sr);
    free_list_temp(temp_sr);
}
