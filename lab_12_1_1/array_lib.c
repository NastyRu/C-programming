#include "array_lib.h"

/*
Выполняется проход по файлу, проверка элементов и подсчет их количества

@param f [in]
@param kol [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int read_kol(FILE *f, const char *argv, int *kol)
{
    int num;

    f = fopen(argv, "r");

    if (f == NULL)
    {
        printf("No file");

        return NO_FILE;
    }

    while (0 == feof(f))
    {
        if (1 == fscanf(f, "%d ", &num))
            (*kol)++;
        else
        {
            fclose(f);

            printf("Incorrect file");

            return INCORRECT_FILE;
        }
    }

    if (EOF == fclose(f))
    {
        printf("Can not close file");
        return INCORRECT_WORK_WITH_FILE;
    }

    return SUCCESS;
}

/*
Выполняется проход по файлу, проверка элементов и считывание их в массив

@param f [in]
@param arrayn [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int read_array(FILE *f, const char *argv, int **arrayn)
{
    int num;

    f = fopen(argv, "r");

    if (f == NULL)
    {
        printf("No file");

        return NO_FILE;
    }

    if (NULL == arrayn)
    {
        printf("Not allocate memory");

        if (EOF == fclose(f))
        {
            return INCORRECT_WORK_WITH_FILE;
        }

        return NO_MEMORY;
    }

    while (0 == feof(f))
    {
        if (1 == fscanf(f, "%d ", &num))
        {
            (**arrayn) = num;
            (*arrayn) += 1;
        }
    }

    if (EOF == fclose(f))
    {
        printf("Can not close file");
        return INCORRECT_WORK_WITH_FILE;
    }

    return SUCCESS;
}

/*
Выполняется запись массива в файл

@param f [out]
@param kol [in]
@param array [in]
*/
void write_in_file(FILE *f, const char *argv, int *array, int kol)
{
    f = fopen(argv, "w");

    for (int i = 0; i < kol; i++)
        fprintf(f, "%d ", *(array + i));

    fclose(f);
}

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

/*
Выполняется проход по массиву и создается новый массив по заданному фильтру
оставляем элементы между макисмальным и минимальным, они в массив не входят

@param pb_src [in]
@param pe_src [in]
@param pb_dst [out]
@param pe_dst [out]

@return SUCCESS если выполнена задача, иначе код ошибки и сообщение
*/
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int min, max;
    int *amin, *amax, *begin;
    int kol;
    int i = 0;

    if (pb_src == pe_src || NULL == pb_src || NULL == pe_src || NULL == pb_dst)
        return INCORRECT_FORM;

    min = max = *pb_src;
    amin = amax = (int*)pb_src;

    while (pb_src < pe_src)
    {
        if (*pb_src < min)
        {
            amin = (int*)pb_src;
            min = *pb_src;
        }
        if (*pb_src > max)
        {
            amax = (int*)pb_src;
            max = *pb_src;
        }

        pb_src++;
    }

    if (labs(amax - amin) < 2)
    {
        printf("No elements");
        return NO_ELEMENTS;
    }

    kol = labs(amin - amax) - 1;

    if (amin < amax)
        begin = amin;
    else
        begin = amax;

    begin++;

    while (i < kol)
    {
        (*(*pb_dst + i)) = *begin;
        i++;
        begin++;
    }

    *pe_dst = *pb_dst + kol;

    return SUCCESS;
}
