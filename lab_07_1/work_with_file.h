#ifndef WORK_WITH_FILES_H
#define WORK_WITH_FILES_H

#define SUCCESS 0
#define NO_FILE 1
#define INCORRECT_FORM 2
#define INCORRECT_FILE 3
#define NO_MEMORY 4
#define NO_ELEMENTS 5
#define INCORRECT_NAME 6
#define INCORRECT_WORK_WITH_FILE 7

int read_kol(FILE *f, const char *argv, int *kol);
int read_array(FILE *f, const char *argv, int **arrayn);
void write_in_file(FILE *f, const char *argv, int *array, int kol);

#endif // WORK_WITH_FILES_H
