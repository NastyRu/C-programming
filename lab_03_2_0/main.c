/*
 Нахождение числа, наиболее близкого к среднему
*/

#include <stdio.h>
#include <math.h>

#define INCORRECT_FORM -1
#define NO_FILE -2
#define INCORRECT_FILE -3
#define TRUE 0

float mean(FILE *f, int *n)
{
    float num;

    float sum = 0;

    while (fscanf(f, "%f", &num) == 1)
    {
        sum += num;
        *n += 1;
    }

    if (*n > 0 && feof(f))
        return sum/ *n;
    else
    {
        *n = 0;
        return INCORRECT_FILE;
    }
}

float nearmean(FILE *f, float meanposl)
{
    float num;
    float min, minrazn;

    rewind(f);

    fscanf(f, "%f", &num);

    minrazn = fabs(meanposl - num);
    min = num;

    while (fscanf(f, "%f", &num) == 1)
    {
        if (fabs(meanposl - num) < minrazn)
        {
            minrazn = fabs(meanposl - num);
            min = num;
        }
    }

    return min;
}

int main(int argc, char** argv)
{
    FILE *f;

    float meanposl, min;
    int n = 0;

    if (argc != 2)
    {
        printf("Incorrected form\nCorrect form: ./main.exe <file-name>");

        return INCORRECT_FORM;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("No file");

        return NO_FILE;
    }

    meanposl = mean(f, &n);

    min = nearmean(f, meanposl);

    if (n == 0)
    {
        printf("Incorrected file");

        return INCORRECT_FILE;
    }
    else
    {
        printf("%f", min);

        return TRUE;
    }

    fclose(f);
}

