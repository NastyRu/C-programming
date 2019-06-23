#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "work_with_file.h"
#include "action_with_matrix.h"

/*
Вычисляет сумму двух матриц. Записывает результат в первую.
@param matrix1 [in]
@param matrix2 [in]
@param n1 [in]
@param n2 [in]
@param m1 [in]
@param m2 [in]

@return Вовзращает NULL, если сложение невозможно. Возвращает конечную матрицу, если все выполнено
*/
double **addition(double **matrix1, double **matrix2, const int n1, const int n2, const int m1, const int m2)
{
    if (n1 == n2 && m1 == m2)
    {
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < m1; j++)
                matrix1[i][j] += matrix2[i][j];

        return matrix1;
    }
    free_matrix(matrix1, n1);
    printf("Impossible amount 2 matrixes\n");
    return NULL;
}

/*
Вычисляет произведение двух матриц. Результат записывает в новую.
@param matrix1 [in]
@param matrix2 [in]
@param n1 [in]
@param n2 [in]
@param m1 [in]
@param m2 [in]
@param n[out]
@param m[out]

@return Вовзращает NULL, если умножение невозможно. Возвращает конечную матрицу, если все выполнено
*/
double **multiplication(double **matrix1, double **matrix2, const int n1, const int n2, const int m1, const int m2, int *n, int *m)
{
    if (m1 == n2)
    {
        *n = n1;
        *m = m2;

        double **matrix = init_matrix(n, m);

        if (NULL == matrix)
        {
            return NULL;
        }

        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                for (int k = 0; k < m1; k++)
                    matrix[i][j] += matrix1[i][k] * matrix2[k][j];

        return matrix;
    }

    printf("Impossible multiplication of 2 matrixes\n");
    return NULL;
}

/*
Меняет 2 строки местами
@param matrix [out]
@param f [out]
@param imax [in]
@param i [in]
@param n [in]
*/
void swap_line(double **matrix, double *f, const int imax, const int i, const int n)
{
    double buf = 0;

    for (int j = 0; j < n; j++)
    {
        buf = matrix[imax][j];
        matrix[imax][j] = matrix[i][j];
        matrix[i][j] = buf;
    }

    buf = f[imax];
    f[imax] = f[i];
    f[i] = buf;
}

/*
Ищет максимум в столбце
@param matrix [in]
@param f [in]
@param column [in]
@param n [in]
*/
void maxim(double **matrix, double *f, const int column, const int n)
{
    double max = matrix[column][column];
    int imax = column;

    for (int i = column; i < n; i++)
        if (max < matrix[i][column])
        {
            imax = i;
            max = matrix[i][column];
        }
    swap_line(matrix, f, imax, column, n);
}

/*
Вычисляет решение СЛАУ методом Гаусса
@param matrix [in]
@param n [in]
@param f [in]
@param x [out]

@return Вовзращает NO_DESISION, если найти решение невозможно. DESISION, если решение найдено
*/
int decision_slau(double **matrix, const int n, double *f, double *x)
{
    double del = 0;
    double **matrix_copy = init_matrix(&n, &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrix_copy[i][j] = matrix[i][j];
        x[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        maxim(matrix_copy, f, j, n);

        for (int i = j + 1; i < n; i++)
        {
            del = matrix_copy[i][j] / matrix_copy[j][j];
            for (int k = 0; k < n; k++)
                matrix_copy[i][k] -= del * matrix_copy[j][k];
            f[i] -= del * f[j];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        float s = 0;
        for (int j = i + 1; j < n; j++)
            s += matrix_copy[i][j] * x[j];
        if (0 == matrix_copy[i][i])
        {
            free_matrix(matrix_copy, n);
            return NO_DESISION;
        }
        x[i] = (f[i] - s) / matrix_copy[i][i];
    }
    free_matrix(matrix_copy, n);
    return DESISION;
}

/*
Вычисляет обратную матрицы методом Гаусса. Результат записывает в новую.
@param matrix [in]
@param n [in]
@param m [in]

@return Вовзращает NULL, если обратить невозможно. Возвращает конечную матрицу, если все выполнено
*/
double **reverse_matrix(double **matrix, const int n, const int m)
{
    if (n == m)
    {
        double **matrix_reverse = init_matrix(&n, &n);
        double *f = calloc(n, sizeof(double));
        double *x = calloc(n, sizeof(double));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (j == i)
                    f[j] = 1;
                else
                    f[j] = 0;

            if (DESISION != decision_slau(matrix, n, f, x))
            {
                printf("Impossible revert matrix\n");
                free(f);
                free(x);
                free_matrix(matrix_reverse, n);
                return NULL;
            }
            else
                for (int j = 0; j < n; j++)
                    matrix_reverse[j][i] = x[j];
        }
        free(f);
        free(x);
        return matrix_reverse;
    }
    printf("Impossible revert matrix\n");
    return NULL;
}
