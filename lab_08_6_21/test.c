#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "work_with_file.h"
#include "action_with_matrix.h"

#define TESTS 17

void read_out_kol(FILE *f, int *n, int *m)
{
    fscanf(f, "%d", n);
    fscanf(f, "%d", m);
}

double **allocate_out_matrix(FILE *f, const char *argv, int *n, int *m)
{
    f = fopen(argv, "r");
    read_out_kol(f, n, m);

    double **matrix = init_matrix(n, m);
    if (NULL == matrix)
    {
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < (*n); i++)
        for (int j = 0; j < (*m); j++)
            fscanf(f, "%lf", &matrix[i][j]);

    fclose(f);
    return matrix;
}

int comparison(const int n1, const int nr, const int m1, const int mr, double **matrix, double **res)
{
    if (n1 != nr || m1 != mr)
    {
        free_matrix(matrix, n1);
        free_matrix(res, nr);
        return FAILED;
    }

    for (int i = 0; i < nr; i++)
        for (int j = 0; j < mr; j++)
            if (fabs(matrix[i][j] - res[i][j]) > EPS)
            {
                free_matrix(matrix, n1);
                free_matrix(res, nr);
                return FAILED;
            }
    free_matrix(matrix, n1);
    free_matrix(res, nr);
    return SUCCESS;
}

int test_write(int *err_cnt)
{
    reference_information();

    FILE *f = NULL;
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0;

    matrix2 = allocate_out_matrix(f, "out_1.txt", &n2, &m2);
    if (SUCCESS == write_matrix(f, "out", n2, m2, matrix2))
    {
        (*err_cnt)++;
    }
    free_matrix(matrix2, n2);

    if (INCORRECT_FILE == write_matrix(f, "out", n2, m2, NULL))
    {
        (*err_cnt)++;
    }

    if (2 == *err_cnt)
        return SUCCESS;
    printf("Failed test in write function\n");
    return FAILED;
}

int test_allocate(int *err_cnt)
{
    FILE *f = NULL;
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0, no_nules2 = 0;

    matrix2 = allocate_matrix(f, "in_13.txt", &n2, &m2, &no_nules2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    matrix2 = allocate_matrix(f, "gdhdk.txt", &n2, &m2, &no_nules2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    matrix2 = allocate_matrix(f, "in_14.txt", &n2, &m2, &no_nules2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    matrix2 = allocate_matrix(f, "in_15.txt", &n2, &m2, &no_nules2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    if (4 == *err_cnt)
        return SUCCESS;
    printf("Failed test in allocate function\n");
    return FAILED;
}

int test_init(int *err_cnt)
{
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0;

    n2 = -1;
    m2 = 3;
    matrix2 = init_matrix(&n2, &m2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    n2 = 1;
    m2 = -3;
    matrix2 = init_matrix(&n2, &m2);
    if (NULL == matrix2)
    {
        (*err_cnt)++;
    }

    if (2 == *err_cnt)
        return SUCCESS;
    printf("Failed test in init function\n");
    return FAILED;
}

int test_amount(int *err_cnt)
{
    FILE *f = NULL;
    double **matrix1 = NULL;
    int n1 = 0, m1 = 0, no_nules1 = 0;
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0, no_nules2 = 0;
    double **res = NULL;
    int nr = 0, mr = 0;
    int kol = 0;

    matrix1 = allocate_matrix(f, "in_11.txt", &n1, &m1, &no_nules1);
    matrix2 = allocate_matrix(f, "in_12.txt", &n2, &m2, &no_nules2);
    matrix1 = addition(matrix1, matrix2, n1, n2, m1, m2);
    res = allocate_out_matrix(f, "out_1.txt", &nr, &mr);

    if (SUCCESS == comparison(n1, nr, m1, mr, matrix1, res))
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix2, n2);

    matrix1 = allocate_matrix(f, "in_11.txt", &n1, &m1, &no_nules1);
    matrix2 = allocate_matrix(f, "in_21.txt", &n2, &m2, &no_nules2);
    matrix1 = addition(matrix1, matrix2, n1, n2, m1, m2);

    if (NULL == matrix1)
    {
        (*err_cnt)++;
        kol++;
    }
    free_matrix(matrix2, n2);

    if (2 == kol)
        return SUCCESS;

    printf("Failed test in amount function\n");
    return FAILED;
}

int test_multiplication(int *err_cnt)
{
    FILE *f = NULL;
    double **matrix1 = NULL;
    int n1 = 0, m1 = 0, no_nules1 = 0;
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0, no_nules2 = 0;
    double **matrix = NULL;
    int n = 0, m = 0;
    double **res = NULL;
    int nr = 0, mr = 0;
    int kol = 0;

    matrix1 = allocate_matrix(f, "in_21.txt", &n1, &m1, &no_nules1);
    matrix2 = allocate_matrix(f, "in_22.txt", &n2, &m2, &no_nules2);
    matrix = multiplication(matrix1, matrix2, n1, n2, m1, m2, &n, &m);
    res = allocate_out_matrix(f, "out_2.txt", &nr, &mr);

    if (SUCCESS == comparison(n, nr, m, mr, matrix, res))
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);

    matrix1 = allocate_matrix(f, "in_11.txt", &n1, &m1, &no_nules1);
    matrix2 = allocate_matrix(f, "in_21.txt", &n2, &m2, &no_nules2);
    matrix = multiplication(matrix1, matrix2, n1, n2, m1, m2, &n, &m);

    if (NULL == matrix)
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);

    matrix1 = allocate_matrix(f, "in_21.txt", &n1, &m1, &no_nules1);
    matrix2 = allocate_matrix(f, "in_22.txt", &n2, &m2, &no_nules2);
    m2 = -1;
    n = 0;
    m = 0;
    matrix = multiplication(matrix1, matrix2, n1, n2, m1, m2, &n, &m);
    if (NULL == matrix)
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);

    if (3 == kol)
        return SUCCESS;

    printf("Failed test in multiplication function\n");
    return FAILED;
}

int test_reverse(int *err_cnt)
{
    FILE *f = NULL;
    double **matrix1 = NULL;
    int n1 = 0, m1 = 0, no_nules1 = 0;
    double **matrix = NULL;
    double **res = NULL;
    int nr = 0, mr = 0;
    int kol = 0;

    matrix1 = allocate_matrix(f, "in_3.txt", &n1, &m1, &no_nules1);
    matrix = reverse_matrix(matrix1, n1, m1);
    res = allocate_out_matrix(f, "out_3.txt", &nr, &mr);

    if (SUCCESS == comparison(n1, nr, m1, mr, matrix, res))
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);

    matrix = allocate_out_matrix(f, "out_rand.txt", &n1, &m1);
    res = allocate_out_matrix(f, "revert_rand_matrix.txt", &nr, &mr);
    if (SUCCESS == comparison(n1, nr, m1, mr, matrix, res))
    {
        (*err_cnt)++;
        kol++;
    }

    matrix1 = allocate_matrix(f, "in_11.txt", &n1, &m1, &no_nules1);
    matrix = reverse_matrix(matrix1, n1, m1);

    if (NULL == matrix)
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);

    matrix1 = allocate_matrix(f, "in_32.txt", &n1, &m1, &no_nules1);
    matrix = reverse_matrix(matrix1, n1, m1);
    if (NULL == matrix)
    {
        (*err_cnt)++;
        kol++;
    }

    free_matrix(matrix1, n1);

    if (4 == kol)
        return SUCCESS;

    printf("Failed test in reverse function\n");
    return FAILED;
}

int main(int argc, char **argv)
{
    int err_cnt = 0;

    test_write(&err_cnt);
    test_init(&err_cnt);
    test_allocate(&err_cnt);
    test_amount(&err_cnt);
    test_multiplication(&err_cnt);
    test_reverse(&err_cnt);

    if (TESTS == err_cnt)
    {
        printf("SUCCESS");
        return SUCCESS;
    }
    printf("FAILED");
    return FAILED;
}
