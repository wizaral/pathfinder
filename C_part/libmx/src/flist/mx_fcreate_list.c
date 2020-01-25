#include "libmx.h"

t_flist *mx_fcreate_list() {
    t_flist *list = malloc(sizeof(t_flist));

    if (list) {
        list->head = list->tail = NULL;
        list->size = 0;
    }
    return list;
}
