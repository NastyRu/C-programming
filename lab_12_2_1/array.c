#include "array.h"

/*
Циклический сдвиг массив влево на несколько позиций
@param array [out]
@param size [in]
@param k [in]
*/
void shift_array(int *array, int size, int k)
{
    int array1[size], array2[size];

    k = k % size;

    for (int i = 0; i < k; i++)
        array1[i] = array[i];

    for (int i = k; i < size; i++)
        array2[i - k] = array[i];

    for (int i = 0; i < size - k; i++)
        array[i] = array2[i];

    for (int i = size - k; i < size; i++)
        array[i] = array1[i - size + k];
}

/*
Проверка является ли число полным квадратом
@param number [in]

@return Возвращает 0, если да. 1, если нет
*/
int square(int number)
{
    if (number < 0)
        return FAILED;
        
    int sq = sqrt(number);

    if (sq * sq == number)
        return SUCCESS;

    return FAILED;
}

/*
Получение массива квадратов из первоначального массива
@param array1 [in]
@param array2 [out]
@param size [in]

@return Возвращает количество полных квадратов
*/
int squares_array(int *array1, int *array2, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (square(array1[i]) == SUCCESS)
        {
            array2[j] = array1[i];
            j++;
        }
    }

    return j;
}
