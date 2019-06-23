#include "function.h"

/*
Дублирование строки с ограничением по количеству элементов
@param a [in]
@param n [in]

@return Возвращает новую строку или NULL при ошибке
*/
char *my_strndup(const char *a, size_t n)
{
    char *copy = malloc((n + 1) * sizeof(char));
    int i = 0;

    if (NULL == copy)
        return NULL;

    while (i < n && a[i] != '\0')
    {
        copy[i] = a[i];
        i++;
    }
    copy[i] = '\0';

    return copy;
}
