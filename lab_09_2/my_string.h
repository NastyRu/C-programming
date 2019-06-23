#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define SUCCESS 0
#define INCORRECT_FILE 1
#define INCORRECT_FORM 2
#define ERR_GETLINE -1
#define NO_MATCHES -2

#define SIZE_BUF 128

int my_sizeof(const char *a);
int my_strcmp(char *line1, char *line2);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int str_search(const char *source, const char *search, int begin);
char *str_replace(const char *source, const char *search, const char *replace);

#endif // MY_STRING_H
