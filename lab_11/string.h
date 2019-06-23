#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define FAILED -1
#define SUCCESS 0

int my_sizeof(const char *a);
void int_to_str(char *str, long int x);
void replace(char *str, char *replace, int i, int kol);
int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...);

#endif // STRING_H
