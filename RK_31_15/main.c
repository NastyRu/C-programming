#include "include.h"

int main(int argc, char **argv)
{
    if (2 != argc)
    {
        printf("Неправильная форма ");
        return INCORRECT_FORM;
    }

    int n = 0, m = 0;
    int **matrix = allocate_matrix(argv[1], &n, &m);

    if (NULL == matrix)
    {
        printf("Некорректные данные");
        return INCORRECT_FORM;
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }*/
    friends(matrix, n, m);
    free_matrix(matrix);

    return SUCCESS;
}
