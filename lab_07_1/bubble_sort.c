#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "bubble_sort.h"
#include "work_with_file.h"

/*
Сравнивает 2 числа

@param x1 [in]
@param x2 [in]

@return Воззвращает отрицательное число, если первое
меньше второго и положительное - если наоборот
*/
int comparator(const void *x1, const void *x2)
{
    return (*(int*)x1 - *(int*)x2);
}

/*
Меняет местами 2 числа

@param a [out]
@param b [out]
@param size [in]
*/
void swap(void *a, void *b, int size)
{
    char *p = a, *q = b, buf;

    for (int i = 0; i < size; i++)
    {
        buf = *(p + i);
        *(p + i) = *(q + i);
        *(q + i) = buf;
    }
}

/*
Сортировка пузырьком. Нечетные и четные проходы выполняются
в противоположных направлениях: нечетные проходы от начала к концу,
четные – от конца массива к его началу. Если за проход элементы
не менялись сортировка заканчивается

@param first [out]
@param count [in]
@param size [in]
*/
void mysort (void *first, int count, int size, int (*comparator)(const void *, const void *))
{
    int left = 0, right = (count - 1) * size;
    int flag = 1;

    while ((left < right) && flag > 0)
    {
        flag = 0;

        for (int i = left; i < right; i += size)
        {
            if (comparator(((char *)first + i), ((char *)first + i + size)) > 0)
            {
                swap(((char *)first + i), ((char *)first + i + size), size);
                flag = 1;
            }
        }

        right -= size;

        for (int i = right; i > left; i -= size)
        {
            if (comparator(((char *)first + i - size), ((char *)first + i)) > 0)
            {
                swap(((char *)first + i - size), ((char *)first + i), size);
                flag = 1;
            }
        }

        left += size;
    }
}
