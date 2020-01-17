#include "libmx.h"

void mx_push_front(t_list *list, void *data) {
    t_list_node *node = NULL;

    if (list && (node = mx_create_node(data, NULL, list->head)) != NULL) {
        list->head = list->head->prev = node;
        ++list->size;
        if (list->tail == NULL)
            list->tail = node;
    }
}
