#include "string.h"

/*
Нахождение размера строки
@param a [in]

@return Возвращает количество элементов в строке
*/
int my_sizeof(const char *a)
{
    int i = 0;

    while (a[i + 1] != '\0')
        i++;

    return ++i;
}

/*
Получение из целого числа строки
@param str [out]
@param x [in]
*/
void int_to_str(char *str, long int x)
{
    int i = 0;
    int buf = 0;

    if (x < 0)
    {
        x = -x;
        buf = 1;
        i++;
    }
    while (x > 0)
    {
        for (int j = i; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = x % 10 + '0';
        x = x / 10;
        i++;
    }
    if (buf)
    {
        for (int j = i; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = '-';
    }
    str[i] = '\0';
}

/*
Замена подстроки в строке
@param str [out]
@param replace [in]
@param i [in]
@param kol [in]

@return Возвращает количество элементов в строке
*/
void replace(char *str, char *replace, int i, int kol)
{
    int rep = my_sizeof(replace), st = my_sizeof(str);
    char *new = calloc(st + rep - kol, sizeof(char));

    for (int j = 0; j < i; j++)
        new[j] = str[j];
    for (int j = i; j < (i + rep); j++)
        new[j] = replace[j - i];
    for (int j = i + kol; j < st; j++)
        new[j + rep - kol] = str[j];

    st = st + rep - kol;
    for (int j = 0; j < st; j++)
        str[j] = new[j];
    str[st] = '\0';
    free(new);
}
