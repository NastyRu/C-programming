#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "test_filter.h"
#include "test_buble_sort.h"

#define SUCCESS 0
#define FAILED 1

int main(void)
{
    if (0 == test_filter() && 0 == test_bubble_sort())
    {
        printf("SUCCESS");
        return SUCCESS;
    }

    return FAILED;
}
