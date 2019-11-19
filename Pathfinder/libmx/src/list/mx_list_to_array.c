#include "libmx.h"

void **mx_list_to_array(t_list *list) {
    void **array = NULL;
    t_list_node *node = list ? list->head : NULL;

    if (list->head && list->tail)
        if ((array = (void **)malloc(sizeof(void *) * list->size)) != NULL)
            for (int i = 0; node; ++i, node = node->next)
                array[i] = node->data;
    return array;
}
