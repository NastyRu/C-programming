#include "work_with_table.h"

int main()
{
    struct temp temp;
    INIT_LIST_HEAD(&temp.list);
    int min_year = 0, max_year;

    read_from_file(&temp, "in.txt", &min_year, &max_year);
    write_to_file(&temp, "file.txt", min_year, max_year);
    free_list(&temp);

    return SUCCESS;
}
