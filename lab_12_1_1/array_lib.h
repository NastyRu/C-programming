#ifndef ARRAY_LIB_H
#define ARRAY_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
int comparator(const void *x1, const void *x2);
void swap(void *a, void *b, int size);
void mysort(void *first, int count, int size, int (*comparator)(const void *, const void *));
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // ARRAY_LIB_H
