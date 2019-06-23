/*
Используемый тип данных integer, занимает в памяти 2 байта.
Выбран алгоритм сортировки пузырьком.
По возрастанию.
*/


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILENAME "new.txt"
#define N 50
#define CANNOT_CLOSE -1
#define TRUE 0

//создание
int make(FILE *f)
{
    int i;
    int num;

    for (i = 1; i <= N; i++)
    {
        num = rand();
        fwrite(&num, sizeof(int), 1, f);
    }

    return TRUE;
}

//вывод
int input(FILE *f)
{
    int i;
    int num;

    rewind(f);

    for (i = 1; i <= N; i++)
    {
        fread(&num, sizeof(int), 1, f);
        printf("%d ", num);
    }

    return TRUE;
}

//нахождение значения по месту
int get_number_by_pos(FILE *f, int n)
{
    rewind(f);

    int ptr;

    if (-1 == fseek(f, n*sizeof(int), SEEK_SET))
    {
        printf("Incorrected position");

        return errno;
    }

    fread(&ptr, sizeof(int), 1, f); //ptr возвращает нужно значение

    return ptr;
}

//перемещение на это место
int put_number_by_pos(FILE *f, int n, int ptr)
{
    rewind(f);

    if (-1 == fseek(f, n*sizeof(int), SEEK_SET))
    {
        printf("Incorrected position");

        return errno;
    }

    fwrite(&ptr, sizeof(int), 1, f);

    return TRUE;
}

//сортировка пузырьком по возрастанию

int sort(FILE *f)
{
    rewind(f);
    int i, j;
    int buf;

    for(i = 0 ; i < N-1; i++)
    {
        for(j = 0 ; j < N-i-1 ; j++)
        {
            if(get_number_by_pos(f, j) > get_number_by_pos(f, j+1))
            {
                buf = get_number_by_pos(f, j);
                put_number_by_pos(f, j,get_number_by_pos(f, j+1));
                put_number_by_pos(f, j+1, buf);
             }
        }
    }

    return TRUE;
}

int main (void)
{
    FILE *f;

    f = NULL;

    f = fopen(FILENAME, "wb+");

    if (NULL == f)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    make(f);

    printf("Initial file\n");
    input(f);

    printf("\nFile\n");

    sort(f);

    input(f);

    if (EOF == fclose(f))
        return CANNOT_CLOSE;

    return TRUE;
}
