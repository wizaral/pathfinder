#include "libmx.h"

size_t mx_fcheck_size(t_flist *list) {
    size_t size = 0;

    for (t_flist_node *node = list ? list->head : NULL; node; ++size)
        node = node->next;
    return list ? list->size = size : -1;
}
