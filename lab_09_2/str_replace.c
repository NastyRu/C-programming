#include "my_string.h"

/*
Поиск вхождения подстроки в строку с какого-то элемента
@param source [in]
@param search [in]
@param begin [in]

@return Возвращает номер позиции с которой найдено совпадения или NO_MATCHES(-2) если не найдено
*/
int str_search(const char *source, const char *search, int begin)
{
    int count = 0;
    for (int i = begin; i < my_sizeof(source); i++)
    {
        if (source[i] == search[0])
        {
            count = 0;
            for (int j = 0; j < my_sizeof(search); j++)
            {
                if (source[j + i] == search[j])
                    count++;
            }
            if (count == my_sizeof(search))
            {
                return i;
            }
        }
    }
    return NO_MATCHES;
}

/*
Замена в строки одной подстроки на другую
@param source [in]
@param search [in]
@param replace [in]

@return Возвращает новую строку или NULL при ошибке
*/
char *str_replace(const char *source, const char *search, const char *replace)
{
    if (NULL == source || NULL == search || NULL == replace)
        return NULL;

    char *copy = calloc(my_sizeof(source) + 1, sizeof(char));
    if (NULL == copy)
        return NULL;

    char *copy_of_copy = NULL;
    int begin = -1;

    for (int i = 0; i < my_sizeof(source); i++)
        copy[i] = source[i];
    copy[my_sizeof(source)] = '\0';

    for (int i = 0; i < my_sizeof(copy); i++)
    {
        begin = str_search(copy, search, i);
        if (begin >= 0)
        {
            copy_of_copy = calloc(my_sizeof(copy) - my_sizeof(search) + my_sizeof(replace) + 1, sizeof(char));
            if (NULL == copy_of_copy)
            {
                free(copy);
                return NULL;
            }

            for (int j = 0; j < begin; j++)
            {
                copy_of_copy[j] = copy[j];
            }
            for (int j = 0; j < my_sizeof(replace); j++)
            {
                copy_of_copy[j + begin] = replace[j];
            }
            for (int j = begin + my_sizeof(replace); j < (my_sizeof(copy) - my_sizeof(search) + my_sizeof(replace)); j++)
            {
                copy_of_copy[j] = copy[j - my_sizeof(replace) + my_sizeof(search)];
            }
            copy_of_copy[my_sizeof(copy) - my_sizeof(search) + my_sizeof(replace)] = '\0';

            i += my_sizeof(replace) - 1;

            if (NULL != copy)
                free(copy);
            copy = calloc(my_sizeof(copy_of_copy) + 1, sizeof(char));
            for (int i = 0; i < my_sizeof(copy_of_copy); i++)
                copy[i] = copy_of_copy[i];
            copy[my_sizeof(copy_of_copy)] = '\0';

            if (NULL != copy_of_copy)
                free(copy_of_copy);
        }
    }

    return copy;
}
