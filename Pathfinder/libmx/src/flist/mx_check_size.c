#include "libmx.h"

t_ll mx_check_size(t_list *list) {
    t_ll size = 0;

    for (t_list_node *node = list ? list->head : NULL; node; node = node->next)
        ++size;
    return list ? list->size = size : -1;
}
