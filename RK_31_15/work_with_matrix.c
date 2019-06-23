#include "include.h"

int **init_matrix(int n, int m)
{
    int **ukazat, *data;
    ukazat = calloc(n, sizeof(int *));
    if (ukazat == NULL)
        return NULL;
    data = calloc(n * m, sizeof(int));
    if (data == NULL)
    {
        free(ukazat);
        return NULL;
    }
    for (int i = 0; i < n; i++)
        ukazat[i] = data + i * m;
    return ukazat;
}

void free_matrix(int **ukazat)
{
    free(ukazat[0]);
    free(ukazat);
}

int read_kol(FILE *f, int *n, int *m)
{
    if (1 != fscanf(f, "%d", n) || *n <= 0)
        return INCORRECT;
    if (1 != fscanf(f, "%d", m) || *m <= 0)
        return INCORRECT;
    if (*n != *m)
        return INCORRECT;
    return SUCCESS;
}

int **allocate_matrix(const char *argv, int *n, int *m)
{
    FILE *f;
    f = fopen(argv, "r");
    if (SUCCESS != read_kol(f, n, m))
        return NULL;

    int **matrix = init_matrix(*n, *m);
    if (NULL == matrix)
    {
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < (*n); i++)
        for (int j = 0; j < (*m); j++)
        {
            if (1 != fscanf(f, "%d", &matrix[i][j]))
                return NULL;
            if (!(matrix[i][j] == 1 || matrix[i][j] == 0))
                return NULL;
        }

    fclose(f);
    return matrix;
}

void friends(int **ukazat, int n, int m)
{
    int min_friends = 6, max_friends = -1;
    int min_name_friends = -1, max_name_friends = -1;
    int *all_max_friends = calloc(n, sizeof(int));
    int *all_min_friends = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int kol = 0;
        for (int j = 0; j < n; j++)
        {
            if (1 == ukazat[i][j])
                kol++;
        }
        if (kol < min_friends)
        {
            min_friends = kol;
            min_name_friends = i;
        }
        if (kol > max_friends)
        {
            max_friends = kol;
            max_name_friends = i;
        }
    }

    all_max_friends[0] = max_name_friends;
    all_min_friends[0] = min_name_friends;

    int imin = 0, imax = 0;

    for (int i = 0; i < n; i++)
    {
        int kol = 0;
        for (int j = 0; j < n; j++)
        {
            if (1 == ukazat[i][j])
                kol++;
        }
        if (max_friends == kol)
        {
            all_max_friends[imax] = i;
            imax++;
        }
        if (min_friends == kol)
        {
            all_min_friends[imin] = i;
            imin++;
        }
    }
    for (int i = 0; i < imin; i++)
        for (int j = 0; j < imax; j++)
            printf("%d %d %d\n", all_min_friends[i], all_max_friends[j], ukazat[all_max_friends[j]][all_min_friends[i]] * ukazat[all_min_friends[i]][all_max_friends[j]]);
    free(all_max_friends);
    free(all_min_friends);
}
