#include "my_string.h"

/*
Получение строки из файла
@param lineptr [out]
@param n [out]
@param stream [in]

@return Возвращает количество записанных элементов или ERR_GETLINE(-1) при ошибке
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    char buf[SIZE_BUF] = { '0' };

    if (NULL == n || NULL == lineptr || NULL == stream)
        return ERR_GETLINE;

    if (NULL == (*lineptr) || 0 == (*n))
    {
        (*lineptr) = calloc(SIZE_BUF, sizeof(char));
        if (NULL == (*lineptr))
            return ERR_GETLINE;
        (*n) = SIZE_BUF;
    }

    ssize_t k = 0;

    while (!feof(stream) && buf[my_sizeof(buf) - 1] != '\n')
    {
        if (NULL == fgets(buf, SIZE_BUF, stream))
            break;

        if ((k + my_sizeof(buf)) >= (*n))
        {
            *lineptr = realloc(*lineptr, k + my_sizeof(buf) + 1);
            (*n) = k + my_sizeof(buf) + 1;
        }
        if (NULL == (*lineptr))
            return ERR_GETLINE;

        for (int i = k; i < k + my_sizeof(buf); i++)
            (*lineptr)[i] = buf[i - k];

        k += my_sizeof(buf);
    }
    (*lineptr)[k] = '\0';

    if (0 == k)
    {
        if (NULL != (*lineptr))
            free(*lineptr);
        return ERR_GETLINE;
    }

    return k;
}
