#include "libmx.h"

void **mx_flist_to_array(t_flist *list) {
    t_flist_node *node = list ? list->head : NULL;
    void **array = NULL;

    if (node && (array = (void **)malloc(sizeof(void *) * list->size)))
        for (size_t i = 0; node; ++i, node = node->next)
            array[i] = node->data;
    return array;
}
