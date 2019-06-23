#include "struct.h"
#include "tree.h"

int kol_elem(int a)
{
    int i = 0;

    if (a < 0)
    {
        a = -a;
        i++;
    }

    if (0 == a)
        return 1;

    while (a > 0)
    {
        a = a / 10;
        i++;
    }
    return i;
}


int print_t(tree_node *tree, int left_is, int delta, int depth, char s[ROWS][COLS], int near)
{
    char b[ROWS];
    int width = 0;

    if (tree == NULL)
        return 0;

    width = kol_elem(tree->data);
    sprintf(b, "%d", tree->data);

    int left  = print_t(tree->left,  1, delta, depth + 1, s, (tree->right) ? 1 : 0);
    int right = print_t(tree->right, 0, delta + left + width, depth + 1, s, (tree->left) ? 1 : 0);

    for (int i = 0; i < width; i++)
        s[2 * depth][delta + i] = b[i];

    if (depth && left_is == 1)
    {
        if (near)
        {
            for (int i = 0; i < width + right + left; i++)
                s[2 * depth - 1][delta + i] = '-';
            s[2 * depth - 1][delta + width + right] = '-';
        }
        s[2 * depth - 1][delta] = '|';
    }
    else if (depth && left_is != 1)
    {
        if (near)
        {
            for (int i = 0; i < width / 2; i++)
                s[2 * depth - 1][delta + i] = '-';
        }
        s[2 * depth - 1][delta - 1] = '-';
        s[2 * depth - 1][delta] = '|';
    }

    return left + width + right;
}

/*
Печать дерева

@param tree [in]
*/
void print_tree(tree_node *tree)
{
    char s[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 1; j++)
            s[i][j] = ' ';
        s[i][COLS - 1] = '\0';
    }

    print_t(tree, 0, 0, 0, s, 0);

    for (int i = 0; i < ROWS; i++)
    {
        int kol = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (s[i][j] == ' ')
                kol++;
        }
        if (COLS - 1 == kol)
            break;
        printf("%s\n", s[i]);
    }
}


/*
Создание дерева

@param data [in]

@return Возвращает указатель на корень или NULL если выделить память не удалось
*/
tree_node *create_node(int data)
{
    tree_node *node = calloc(1, sizeof(tree_node));
    if (NULL == node)
    {
        printf("No memory");
        return NULL;
    }
    if (node)
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

/*
Добавление узла дерева

@param tree [in]
@param data [in]

@return Возвращает указатель на корень дерева или NULL при ошибке
*/
tree_node *add_node(tree_node *tree, int data)
{
    if (tree == NULL)
        tree = create_node(data);
    else if (data < tree->data)
        tree->left = add_node(tree->left, data);
    else
        tree->right = add_node(tree->right, data);

    return tree;
}

/*
Осовобождение памяти

@param tree [in]
*/
void free_tree(tree_node *tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}
