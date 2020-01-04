#include "libmx.h"

void mx_fpop_front(t_flist *list) {
    if (list && list->head) {
        t_flist_node *temp = list->head;

        list->head = list->head->next;
        --list->size;
        free(temp);
        if (list->head == NULL)
            list->tail = NULL;
    }
}
