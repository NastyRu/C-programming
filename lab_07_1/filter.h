#ifndef FILTER_H
#define FILTER_H

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int fill_new_array(const int *begin, const int *end, int **new_array);

#endif // FILTER_H
