#include "my_string.h"

/*
Нахождение размера строки
@param a [in]

@return Возвращает количество элементов в строке
*/
int my_sizeof(const char *a)
{
    int i = 0;

    while (a[i] != '\0')
        i++;

    return i;
}

/*
Сравнение двух строк
@param line1 [in]
@param line2 [in]

@return Возвращает SUCCESS если строки совпадают или NO_MATCHES(-2) если не совпадают
*/
int my_strcmp(char *line1, char *line2)
{
    int i = 0;
    int len1 = my_sizeof(line1), len2 = my_sizeof(line2);

    while (i < len1 && i < len2)
    {
        if (line1[i] != line2[i])
            return NO_MATCHES;
        i++;
    }
    if (i != len1 || i != len2)
        return NO_MATCHES;

    return SUCCESS;
}
