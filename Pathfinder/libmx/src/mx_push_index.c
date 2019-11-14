#include "libmx.h"

void mx_push_index(t_list **list, void *data, int index) {
    int position = 0;
    int size = mx_list_size(*list);
    t_list *new_node = NULL;
    t_list *prev_node = list ? *list : NULL;

    if (list) {
        if (index <= 0)
            mx_push_front(list, data);
        else if (index >= size)
            mx_push_back(list, data);
        else if ((new_node = mx_create_node(data)) != NULL) {
            while (position + 1 != index) {
                prev_node = prev_node->next;
                ++position;
            }

            new_node->next = prev_node->next;
            prev_node->next = new_node;
        }
    }
}
