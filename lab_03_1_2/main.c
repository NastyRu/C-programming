/*
 Нахождение первого вхождения максимального элемента
*/

#include <stdio.h>

#define FILENAME "new.txt"
#define NO_INPUT_DATA -1
#define CANNOT_CLOSE -2
#define INCORRECT_FILE -3
#define TRUE 0

// Ввод значений, запись в файл
int input(FILE *f)
{
    int x, n =0;

    int t = 1;

    if (EOF == fclose(f))
        return CANNOT_CLOSE;

    f = fopen(FILENAME, "w");

    printf("Input elements ");
    while (t > 0)
    {
        t = scanf("%d",&x);
        if (t > 0)
        {
            n += 1;
            fprintf(f,"%d\n",x);
        }
    }

    if (EOF == fclose(f))
        return CANNOT_CLOSE;

    return n;
}

// Нахождение позиции максимального
int process(FILE *f, int n)
{
    int t;

    int i, imax = 1;
    int max, num;

    f = fopen(FILENAME, "r");
    t = fscanf(f, "%d", &max);

    if (t>0)
    {
        for (i = 2;i <= n;i++)
        {
            fscanf(f, "%d", &num);
            if (num > max)
            {
                max = num;
                imax = i;
            }
        }

        return imax;
    }
    else
        return NO_INPUT_DATA;

    if (EOF == fclose(f))
        return CANNOT_CLOSE;
}

int main(void)
{
    FILE *f;

    int imax;

    if (f = fopen(FILENAME, "r"))
    {
        imax = process(f, input(f));

        if (imax > 0)
        {
            printf("%d", imax);
            return TRUE;
        }
        else
        {
            printf("No input data");

            return NO_INPUT_DATA;
        }
    }
    else
        return INCORRECT_FILE;
}
