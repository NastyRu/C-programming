#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SUCCESS 0
#define FAILED 1

void shift_array(int *array, int size, int k);
int square(int number);
int squares_array(int *array1, int *array2, int size);

#endif // ARRAY_H
