#include "libmx.h"

void mx_clear_list(t_list *list) {
    t_list_node *temp = list ? list->head : NULL;

    if (list) {
        while (temp) {
            temp = list->head->next;
            free(list->head);
            list->head = temp;
            --list->size;
        }
        list->head = list->tail = NULL;
    }
}
