#include "libmx.h"

long long mx_check_size(t_forward_list *list) {
    long long size = 0;

    for (t_list_node *node = list ? list->head : NULL; node; node = node->next)
        ++size;

    return list ? list->size = size : -1;
}
