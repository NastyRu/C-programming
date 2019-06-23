#include "work_with_table.h"

int main(int argc, char **argv)
{
    struct temp temp_ekb, temp_spb, temp_stc;
    INIT_LIST_HEAD(&temp_ekb.list);
    INIT_LIST_HEAD(&temp_spb.list);
    INIT_LIST_HEAD(&temp_stc.list);
    int min_year = 0, max_year;

    read_from_file(&temp_ekb, "EKB.csv", &min_year, &max_year);
    write_to_file(&temp_ekb, "EKB.txt", min_year, max_year);
    free_list(&temp_ekb);

    read_from_file(&temp_spb, "SPB.csv", &min_year, &max_year);
    write_to_file(&temp_spb, "SPB.txt", min_year, max_year);
    free_list(&temp_spb);

    read_from_file(&temp_stc, "STC.csv", &min_year, &max_year);
    write_to_file(&temp_stc, "STC.txt", min_year, max_year);
    free_list(&temp_stc);

    return SUCCESS;
}
