#include "libmx.h"

void mx_fclear_list(t_flist *list) {
    if (list) {
        t_flist_node *temp = list->head;

        while (temp) {
            temp = list->head->next;
            free(list->head);
            list->head = temp;
        }
        list->head = list->tail = NULL;
        list->size = 0;
    }
}
