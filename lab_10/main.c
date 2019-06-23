#include "struct.h"
#include "tree.h"

int main(int argc, char **argv)
{
    if (2 != argc)
    {
        printf("Incorrect form\n Correct: ./app.exe file.txt");
        return INCORRECT_FORM;
    }
    FILE *f = fopen(argv[1], "r");
    if (NULL == f)
    {
        printf("Incorrect file");
        return INCORRECT_FILE;
    }
    int x = 0;
    tree_node *trees = NULL;

    while (!feof(f))
    {
        if (1 != fscanf(f, "%d\n", &x))
        {
            printf("Incorrect file");
            fclose(f);
            free_tree(trees);
            return INCORRECT_FILE;
        }
        trees = add_node(trees, x);
        if (NULL == trees)
            return NO_MEMORY;
    }
    fclose(f);
    print_tree(trees);
    free_tree(trees);
    return SUCCESS;
}
