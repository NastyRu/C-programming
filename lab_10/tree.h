#ifndef TREE_H
#define TREE_H

#define INCORRECT_FORM 3
#define INCORRECT_FILE 4
#define NO_MEMORY 5

#define ROWS 60
#define COLS 201

typedef struct tree_node tree_node;
struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

tree_node *create_node(int data);

tree_node *add_node(tree_node *tree, int data);

void free_tree(tree_node *tree);

void print_tree(tree_node *tree);

int print_t(tree_node *tree, int is_left, int offset, int depth, char s[ROWS][COLS], int near);

#endif // TREE_H
