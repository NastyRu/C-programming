#include "struct.h"

/*
Поиск элемента в списке

@param x1 [in]
@param x2 [in]

@return Возвращает 0 если структуры равны и не 0 если не равны
*/
node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *))
{
    while (head != NULL)
    {
        if (SUCCESS == comparator(head->data, data))
            return head;
        head = head->next;
    }
    return NULL;
}

/*
Вставка элемента до какого-то элемента

@param head [out]
@param elem [in]
@param before [in]
*/
void insert(node_t **head, node_t *elem, node_t *before)
{
    if (NULL == head || NULL == (*head) || NULL == elem || NULL == before)
        return;
    node_t *buffer = (*head);

    if (buffer == before)
    {
        (*head) = elem;
        (*head)->next = before;
        return;
    }
    while (buffer->next != before)
    {
        buffer = buffer->next;
        if (NULL == buffer)
            return;
    }
    buffer->next = elem;
    buffer = buffer->next;
    buffer->next = before;
}

/*
Значение элемента по номеру в списке

@param list [in]
@param n [in]

@return Возвращает указатель на структуру
*/
node_t *number_list(node_t *list, int n)
{
    for (int i = 0; i < n; i++)
        list = list->next;
    return list;
}

/*
Уадление повторений

@param head [out]
@param comparartor [in]
*/
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (NULL == *head || NULL == head)
        return;

    node_t *buffer = *head, *buf = NULL, *copy = NULL, *iter = NULL;
    while (buffer != NULL)
    {
        copy = buffer;
        iter = buffer->next;
        while (iter != NULL)
        {
            if (SUCCESS == comparator(iter->data, buffer->data))
            {
                buf = copy->next = iter->next;
                free(iter);
                iter = buf;
                continue;
            }
            copy = iter;
            iter = iter->next;
        }
        buffer = buffer->next;
    }
}

/*
Добавление в конец

@param head [in]
@param data [in]

@return Возвращает список с добавленным в конец элементом
*/
node_t *add_in_end(node_t *head, node_t *data)
{
    node_t *buf = head;

    if (!head)
    {
        data->next = NULL;
        return data;
    }
    for (; buf->next; buf = buf->next);
    buf->next = data;
    buf = buf->next;
    buf->next = NULL;
    return head;
}

/*
Вставка в остортированную область

@param head [out]
@param element [in]
@param comparator [in]
*/
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *buf = (*head);
    element->next = NULL;

    while (buf != NULL && comparator(buf->data, element->data) < 0)
        buf = buf->next;
    if (buf != NULL)
    {
        insert(head, element, buf);
    }
    else
    {
        (*head) = add_in_end(*head, element);
    }
}

/*
Сортировка

@param head [out]
@param comparator [in]

@return Возвращает отсортированную структуру или NULL, если нет входных данных
*/
node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sorted = NULL;

    while (head != NULL)
    {
        node_t *buffer = head;
        head = head->next;
        sorted_insert(&sorted, buffer, comparator);
    }
    return sorted;
}
