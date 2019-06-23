#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "work_with_file.h"
#include "action_with_matrix.h"

int main(int argc, char **argv)
{
    FILE *f = NULL;
    double **matrix1 = NULL;
    int n1 = 0, m1 = 0, no_nules1 = 0;
    double **matrix2 = NULL;
    int n2 = 0, m2 = 0, no_nules2 = 0;

    if (4 == argc && 0 == strcmp(argv[1], "h"))
    {
        reference_information();
        return SUCCESS;
    }
    if (argc < 4)
    {
        printf("Incorrected form\nCorrect form: ./main.exe action(h,a,m,o) <file-name> [<file-name>] <file-name>");
        return INCORRECT_FORM;
    }

    matrix1 = allocate_matrix(f, argv[2], &n1, &m1, &no_nules1);
    if (NULL == matrix1)
        return INCORRECT_FILE;

    if (5 == argc && 0 == strcmp(argv[1], "a"))
    {
        matrix2 = allocate_matrix(f, argv[3], &n2, &m2, &no_nules2);
        if (NULL == matrix2)
        {
            free_matrix(matrix1, n1);
            return INCORRECT_FILE;
        }
        matrix1 = addition(matrix1, matrix2, n1, n2, m1, m2);
        free_matrix(matrix2, n2);
        if (NULL == matrix1)
            return IMPOSSIBLE_AMOUNT;
        write_matrix(f, argv[4], n1, m1, matrix1);
        free_matrix(matrix1, n1);
    }
    else if (5 == argc && 0 == strcmp(argv[1], "m"))
    {
        matrix2 = allocate_matrix(f, argv[3], &n2, &m2, &no_nules2);
        if (NULL == matrix2)
        {
            free_matrix(matrix1, n1);
            return INCORRECT_FILE;
        }
        double **matrix = NULL;
        int n = 0, m = 0;
        matrix = multiplication(matrix1, matrix2, n1, n2, m1, m2, &n, &m);
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
        if (NULL == matrix)
            return IMPOSSIBLE_MULTIPLICATION;
        write_matrix(f, argv[4], n, m, matrix);
        free_matrix(matrix, n);
    }
    else if (4 == argc && 0 == strcmp(argv[1], "o"))
    {
        double **matrix = NULL;
        matrix = reverse_matrix(matrix1, n1, m1);
        free_matrix(matrix1, n1);
        if (NULL == matrix)
            return IMPOSSIBLE_REVERSE;
        write_matrix(f, argv[3], n1, n1, matrix);
        free_matrix(matrix, n1);
    }
    else
    {
        printf("Incorrected form\nCorrect form: ./main.exe action(h,a,m,o) <file-name> [<file-name>] <file-name>");
        free_matrix(matrix1, n1);
        return INCORRECT_FORM;
    }
    return SUCCESS;
}
