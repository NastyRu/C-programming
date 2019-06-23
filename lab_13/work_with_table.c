#include "work_with_table.h"

/*
Чтение из файла в структуру
@param temp [out]
@param filename [in]
@param min_year [out]
@param max_year [out]
*/
void read_from_file(struct temp *temp, const char *filename, int *min_year, int *max_year)
{
    struct temp *buf;
    FILE *f = fopen(filename, "r");

    *min_year = 0;
    *max_year = 0;

    while(!feof(f))
    {
        buf = (struct temp *)calloc(1, sizeof(struct temp));
        fscanf(f, "%d %d %d %d %d\n", &buf->year, &buf->month, &buf->day, &buf->max, &buf->min);
        if (*min_year == 0)
            *min_year = buf->year;
        *max_year = buf->year;

        list_add(&(buf->list), &(temp->list));
    }
    fclose(f);
}

/*
Запись в файл полученной структуры
@param temp [in]
@param filename [in]
@param min_year [in]
@param max_year [in]
*/
void write_to_file(struct temp *temp, const char *filename, int min_year, int max_year)
{
    struct list_head *beg;
    struct temp *buf;
    int *delta = calloc(max_year - min_year + 1, sizeof(int));
    int now_year, last_year = min_year, min_temp = 100000, max_temp = -100000;

    list_for_each(beg, &(temp->list))
    {
        buf = list_entry(beg, struct temp, list);
        now_year = buf->year;
        if (now_year == last_year)
        {
            if (buf->max > max_temp)
                max_temp = buf->max;
            if (buf->min < min_temp)
                min_temp = buf->min;
        }
        else
        {
            delta[last_year - min_year] = max_temp - min_temp;
            min_temp = buf->min;
            max_temp = buf->max;
        }
        last_year = buf->year;
    }
    delta[last_year - min_year] = max_temp - min_temp;

    FILE *f = fopen(filename, "w");
    for (int i = 0; i <= (max_year - min_year); i++)
    {
        fprintf(f, "%d %d \n", i + min_year, delta[i]);
    }
    fclose(f);
    free(delta);
}

/*
Освобождение памяти
@param temp [in]
*/
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
