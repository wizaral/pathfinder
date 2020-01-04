#include "libmx.h"

void mx_fpush_front(t_flist *list, void *data) {
    t_flist_node *node = NULL;

    if (list && (node = mx_fcreate_node(data, list->head)) != NULL) {
        list->head = node;
        ++list->size;
        if (list->tail == NULL)
            list->tail = node;
    }
}
