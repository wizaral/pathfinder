#include "libmx.h"

void mx_push_index(t_list *list, void *data, t_ll index) {
    t_list_node *prev_node = list ? list->head : NULL;
    t_list_node *new_node = NULL;

    if (list) {
        if (index <= 0)
            mx_push_front(list, data);
        else if (index >= list->size)
            mx_push_back(list, data);
        else {
            for (t_ll pos = 0; ++pos < index; prev_node = prev_node->next);
            if ((new_node = mx_create_node(data, prev_node->next)) != NULL)
                prev_node->next = new_node;
        }
    }
}
