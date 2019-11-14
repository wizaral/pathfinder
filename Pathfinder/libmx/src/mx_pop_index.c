#include "libmx.h"

void mx_pop_index(t_list **list, int index) {
    int position = 0;
    t_list *del_node = NULL;
    t_list *prev_node = list ? *list : NULL;
    int size = list ? mx_list_size(*list) : 0;

    if (list && *list) {
        if (index <= 0)
            mx_pop_front(list);
        else if (index >= size - 1)
            mx_pop_back(list);
        else if (*list) {
            while (position + 1 != index) {
                prev_node = prev_node->next;
                position++;
            }
            del_node = prev_node->next;
            prev_node->next = del_node->next;
            free(del_node);
        }
    }
}
