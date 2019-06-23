#include "my_string.h"

int main(int argc, char **argv)
{
    if (argc != 7 || SUCCESS != my_strcmp(argv[3], "-s") || SUCCESS != my_strcmp(argv[5], "-r"))
    {
        printf("Incorrect form. \nCorrect: app.exe in.txt out.txt –s search –r replace");
        return INCORRECT_FORM;
    }

    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL)
    {
        printf("Incorrect file");
        return INCORRECT_FILE;
    }
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL)
    {
        fclose(in_file);
        printf("Incorrect file");
        return INCORRECT_FILE;
    }
    const char *search = argv[4];
    const char *replace = argv[6];
    char *line = NULL, *end_line = NULL;
    size_t n;

    if (my_getline(&line, &n, in_file) == ERR_GETLINE)
    {
        printf("Getline error");
        fclose(in_file);
        fclose(out_file);
        return ERR_GETLINE;
    }
    do
    {
        end_line = str_replace(line, search, replace);
        fprintf(out_file, "%s", end_line);
        if (NULL != line)
            free(line);
        if (NULL != end_line)
            free(end_line);
        n = 0;
    }
    while (my_getline(&line, &n, in_file) != ERR_GETLINE);

    fclose(in_file);
    fclose(out_file);
    return SUCCESS;
}
