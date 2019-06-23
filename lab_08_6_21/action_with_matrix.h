#ifndef ACTION_WITH_MATRIX_H
#define ACTION_WITH_MATRIX_H

double **addition(double **matrix1, double **matrix2, int n1, int n2, int m1, int m2);
double **multiplication(double **matrix1, double **matrix2, const int n1, const int n2, const int m1, const int m2, int *n, int *m);
double **reverse_matrix(double **matrix, const int n1, const int m1);
void swap_line(double **matrix, double *f, const int imax, const int i, const int n);
void maxim(double **matrix, double *f, const int column, const int n);
int decision_slau(double **matrix, const int n, double *f, double *x);
double **reverse_matrix(double **matrix, const int n, const int m);

#endif // ACTION_WITH_MATRIX_H
