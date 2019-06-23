#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

int comparator(const void *x1, const void *x2);
void swap(void *a, void *b, int size);
void mysort(void *first, int count, int size, int (*comparator)(const void *, const void *));

#endif // BUBBLE_SORT_H
