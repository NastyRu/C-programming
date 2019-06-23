/* Посчитать среднюю температуру каждого месяца каждого года,
и внутри года отсортировать месяцы по возрастанию средней температуры*/

#include "work_with_file.h"

int main(int argc, char **argv)
{
    struct temp temp_spb;
    INIT_LIST_HEAD(&temp_spb.list);

    read_from_file(&temp_spb, argv[2]);
    table_temp(&temp_spb);
    free_list(&temp_spb);

    return SUCCESS;
}
