#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define INCORRECT_FORM 1
#define INCORRECT 2

int **init_matrix(int n, int m);
void free_matrix(int **ukazat);
int read_kol(FILE *f, int *n, int *m);
int **allocate_matrix(const char *argv, int *n, int *m);
void friends(int **ukazat, int n, int m);
