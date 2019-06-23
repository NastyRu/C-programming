#ifndef WORK_WITH_FILE_H
#define WORK_WITH_FILE_H

#define SUCCESS 0
#define NO_FILE 1
#define INCORRECT_FORM 2
#define INCORRECT_FILE 3
#define NO_MEMORY 4
#define INCORRECT_WORK_WITH_FILE 5
#define IMPOSSIBLE_AMOUNT 6
#define IMPOSSIBLE_MULTIPLICATION 7
#define IMPOSSIBLE_REVERSE 8
#define NO_DESISION 9
#define MANY_DESISIONS 10
#define DESISION 11
#define FAILED 12

#define EPS 0.0001

void reference_information();
int write_matrix(FILE *f, const char *argv, const int n, const int m, double **matrix);
int read_kol(FILE *f, int *n, int *m, int *nules);
double **init_matrix(const int *n, const int *m);
double **allocate_matrix(FILE *f, const char *argv, int *n, int *m, int *nules);
void free_matrix(double **matrix, const int n);

#endif // WORK_WITH_FILE_H
