#include "struct.h"
#include "tree.h"

#define TESTS 13

/*
Создание списка

@param data [in]

@return Возвращает указатель на начало списка
*/
node_t *create_person(int *data)
{
    node_t *pers = calloc(1, sizeof(node_t));
    if (pers != NULL)
    {
        pers->data = data;
        pers->next = NULL;
    }
    return pers;
}

/*
Добавление элемента списка

@param head [in]
@param data [in]

@return Возвращает указатель на начало списка или NULL при ошибке
*/
node_t *add_end(node_t *head, int *data)
{
    node_t *cur = head;
    node_t *pers = create_person(data);

    if (!head)
        return pers;

    while (cur->next != NULL)
        cur = cur->next;
    cur->next = pers;

    return head;
}

/*
Сравнение целых

@param x1 [in]
@param x2 [in]

@return Возвращает 0 если совпадают и другое значение если нет
*/
int int_comparator(const void *x1, const void *x2)
{
    return *(int *)x1 - *(int *)x2;
}

/*
Сравнение списков

@param x1 [in]
@param x2 [in]

@return Возвращает SUCCESS если совпадают и FAILED если нет
*/
int compare(node_t *x1, node_t *x2)
{
    while (x1 != NULL && x2 != NULL)
    {
        if (*(int *)x1->data != *(int *)x2->data)
            return FAILED;
        x1 = x1->next;
        x2 = x2->next;
    }
    return SUCCESS;
}

/*
Осовобождение памяти

@param list [in]
*/
void free_list(node_t *list)
{
    while (list != NULL)
    {
        node_t *copy = list->next;
        free(list);
        list = copy;
    }
}

int test_find(int *err_cnt)
{
    int a[] = { 1, 4, 0, -1, 3, 5, 2, 7, 7, -2 }, b[] = { 1, 2, 0, 3, -2 };
    node_t *res = NULL;
    int count = 0;

    for (int i = 0; i < 10; i++)
        res = add_end(res, a + i);

    if (number_list(res, 2) == find(res, a + 2, int_comparator))
        count++;

    free_list(res);
    res = NULL;

    for (int i = 0; i < 5; i++)
        res = add_end(res, b + i);

    if (NULL == find(res, a + 1, int_comparator))
        count++;

    free_list(res);

    if (2 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }

    printf("Failed in find function\n");
    return FAILED;
}

int test_insert(int *err_cnt)
{
    node_t *res = NULL, *in = NULL;
    int count = 0;

    insert(&res, NULL, NULL);

    if (NULL == res)
        count++;

    int b[] = { 1, 2, 0, 3, -2 };
    int x[] = { -1, -1 };
    node_t *x3 = create_person(x), *x4 = create_person(x + 1);

    for (int i = 0; i < 5; i++)
    {
        res = add_end(res, b + i);
        in = add_end(in, b + i);
    }

    insert(&res, x3, x4);
    if (SUCCESS == compare(res, in))
        count++;

    free_list(res);
    free_list(x3);
    free_list(x4);
    free_list(in);

    if (2 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }

    printf("Failed in insert function\n");
    return FAILED;
}

int test_remove_duplicates(int *err_cnt)
{
    int a[] = { 1, 1, 2, 2, 3, 2, 4, 6, 7, 9, 1, 1, 6, -2, -2 };
    int b[] = { 1, 2, 3, 4, 6, 7, 9, -2 };
    node_t *in = NULL, *res = NULL;
    int count = 0;

    remove_duplicates(&in, int_comparator);
    if (NULL == in)
        count++;

    for (int i = 0; i < 15; i++)
        in = add_end(in, a + i);
    for (int i = 0; i < 8; i++)
        res = add_end(res, b + i);

    remove_duplicates(&in, int_comparator);

    if (SUCCESS == compare(in, res))
        count++;

    free_list(in);
    free_list(res);

    if (2 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }
    printf("Failed in remove duplicate function\n");
    return FAILED;
}

int test_sort(int *err_cnt)
{
    int count = 0;
    node_t *copy = NULL, *res = NULL;
    int a[] = { 3, 2, 1, 4, 5, 5, 2, 3, 0, -1 }, b[] = { -1, 0, 1, 2, 2, 3, 3, 4, 5, 5 };

    for (int i = 0; i < 10; i++)
    {
        copy = add_end(copy, a + i);
        res = add_end(res, b + i);
    }

    node_t *sorted = sort(copy, int_comparator);
    if (SUCCESS == compare(sorted, res))
        count++;

    free_list(sorted);
    free_list(res);

    if (NULL == sort(NULL, int_comparator))
        count++;

    if (2 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }
    printf("Failed in sort function\n");
    return FAILED;
}

int test_create_node(int *err_cnt)
{
    int x = 5, count = 0;

    tree_node *trees = create_node(x);
    if (trees->data == x)
        count++;

    free_tree(trees);

    if (1 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }

    printf("Failed in create node tree function");
    return FAILED;
}

int test_add_node(int *err_cnt)
{
    int x1 = 5, x2 = 6, x3 = 2, count = 0;
    tree_node *trees = NULL;

    trees = add_node(trees, x1);
    if (trees->data == x1)
        count++;

    trees = add_node(trees, x2);
    if (trees->data == x1 && trees->right->data == x2)
        count++;

    print_tree(trees);
    free_tree(trees);

    trees = NULL;
    trees = add_node(trees, x1);
    if (trees->data == x1)
        count++;

    trees = add_node(trees, x3);
    if (trees->data == x1 && trees->left->data == x3)
        count++;

    free_tree(trees);

    if (4 == count)
    {
        (*err_cnt) += count;
        return SUCCESS;
    }

    printf("Failed in add node tree function");
    return FAILED;
}

int main(int argc, char **argv)
{
    int err_cnt = 0;

    test_sort(&err_cnt);
    test_find(&err_cnt);
    test_remove_duplicates(&err_cnt);
    test_insert(&err_cnt);
    test_add_node(&err_cnt);
    test_create_node(&err_cnt);

    if (TESTS == err_cnt)
    {
        printf("SUCCESS");
        return SUCCESS;
    }

    return FAILED;
}
