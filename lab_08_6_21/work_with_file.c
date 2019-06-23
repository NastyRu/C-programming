#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "work_with_file.h"

/*
Вывод информации о программе
*/
void reference_information()
{
    printf("You can:\n\
    Add 2 matrices. Format: ./app.exe a <file1> <file2> <file>\n\
    Multiply 2 matrices. Format: ./app.exe m <file1> <file2> <file>\n\
    Reverse matrice. Format: ./app.exe o <file1> <file>\n");
}

/*
Освобождение памяти выделленой под матрицу
@param matrix [in]
@param n [in]
*/
void free_matrix(double **matrix, const int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

/*
Запись матрицы в файл
@param f [in]
@param argv [in]
@param matrix [in]
@param n [in]
@param m [in]

@return Возвращает SUCCESS, если запись выполенена. INCORRECT_WORK_WITH_FILE, если произошла ошибка закрытия
*/
int write_matrix(FILE *f, const char *argv, const int n, const int m, double **matrix)
{
    if (NULL == matrix)
        return INCORRECT_FILE;
    f = fopen(argv, "w");

    fprintf(f, "%d %d\n", n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%f ", matrix[i][j]);
        fprintf(f, "\n");
    }

    if (EOF == fclose(f))
    {
        printf("Incorrect work with file");
        return INCORRECT_WORK_WITH_FILE;
    }
    return SUCCESS;
}

/*
Чтение размеров матрицы из файла
@param f [in]
@param n [out]
@param m [out]
@param no_nules [out]

@return Возвращает SUCCESS, если матрица записана. INCORRECT_FILE, если файл некорректный
*/
int read_kol(FILE *f, int *n, int *m, int *no_nules)
{
    if (1 == fscanf(f, "%d", n) && (*n) > 0)
        if (1 == fscanf(f, "%d", m) && (*m) > 0)
            if (1 == fscanf(f, "%d\n", no_nules) && (*no_nules) >= 0 && (*no_nules) <= (*n) * (*m))
                return SUCCESS;
    printf("Incorrect file\n");
    return INCORRECT_FILE;
}

/*
Инициализация матрицы из файла
@param n [out]
@param m [out]

@return Возвращает матрицу, если матрица инициализирована. NULL, если невозможно
*/
double **init_matrix(const int *n, const int *m)
{
    double **matrix = calloc(*n, sizeof(double*));
    if (matrix == NULL)
    {
        printf("No memory\n");
        return NULL;
    }

    for (int i = 0; i < *n; i++)
    {
        matrix[i] = calloc(*m, sizeof(double));
        if (matrix[i] == NULL)
        {
            free_matrix(matrix, *n);
            printf("No memory\n");
            return NULL;
        }
    }

    return matrix;
}

/*
Чтение матрицы из файла
@param f [in]
@param argv[in]
@param n [out]
@param m [out]
@param no_nules [out]

@return Возвращает матрицу, если матрица прочитана. NULL, если невозможно
*/
double **allocate_matrix(FILE *f, const char *argv, int *n, int *m, int *no_nules)
{
    int k = 0, l = 0;

    f = fopen(argv, "r");
    if (NULL == f)
    {
        printf("No file\n");
        return NULL;
    }

    if (SUCCESS != read_kol(f, n, m, no_nules))
    {
        fclose(f);
        return NULL;
    }

    double **matrix = init_matrix(n, m);
    if (NULL == matrix)
    {
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < (*no_nules); i++)
    {
        if (1 == fscanf(f, "%d", &k) && 1 == fscanf(f, "%d", &l))
        {
            if (k > *n || l > *m || k <= 0 || l <= 0 || 1 != fscanf(f, "%lf\n", &matrix[k - 1][l - 1]))
            {
                printf("Incorrect file\n");
                free_matrix(matrix, *n);
                fclose(f);
                return NULL;
            }
        }
        else
        {
            printf("Incorrect file\n");
            fclose(f);
            free_matrix(matrix, *n);
            return NULL;
        }
    }

    if (EOF == fclose(f))
    {
        printf("Incorrect work with file\n");
        free_matrix(matrix, *n);
        return NULL;
    }
    return matrix;
}
