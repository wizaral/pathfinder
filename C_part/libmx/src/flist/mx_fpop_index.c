#include "libmx.h"

void mx_fpop_index(t_flist *list, size_t index) {
    if (list && list->head) {
        if (index <= 0)
            mx_fpop_front(list);
        else if (index >= list->size - 1)
            mx_fpop_back(list);
        else {
            t_flist_node *del_node = NULL;
            t_flist_node *prev_node = list->head;

            for (size_t pos = 0; ++pos < index; prev_node = prev_node->next);
            del_node = prev_node->next;
            prev_node->next = del_node->next;
            free(del_node);
            --list->size;
        }
    }
}
