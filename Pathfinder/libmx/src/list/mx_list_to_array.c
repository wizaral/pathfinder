#include "libmx.h"

void **mx_list_to_array(t_list *list) {
    void **array = NULL;
    t_list_node *node = list ? list->head : NULL;

    if (list && list->head && list->tail
        && (array = (void **)malloc(sizeof(void *) * (list->size + 1))))
    {
        for (int i = 0; node; ++i, node = node->next)
            array[i] = node->data;
        array[list->size] = NULL;
    }
    return array;
}
