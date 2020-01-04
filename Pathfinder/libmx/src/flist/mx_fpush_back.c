#include "libmx.h"

void mx_fpush_back(t_flist *list, void *data) {
    t_flist_node *node = NULL;

    if (list && (node = mx_fcreate_node(data, NULL)) != NULL) {
        if (list->tail)
            list->tail = list->tail->next = node;
        else
            list->head = list->tail = node;
        ++list->size;
    }
}
