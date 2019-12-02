#include "libmx.h"

void mx_pop_back(t_list *list) {
    t_list_node *temp = NULL;

    if (list && list->head && list->head != list->tail) {
        temp = list->head;

        while (temp->next->next)
            temp = temp->next;

        free(temp->next);
        temp->next = NULL;

        list->tail = temp;
        --list->size;
    }
    else if (list && list->head) {
        free(list->head);
        list->head = list->tail = NULL;
    }
}
