#include "libmx.h"

void mx_clear_list(t_list **list) {
    t_list *temp = NULL;

    if (list) {
        while (*list) {
            temp = (*list)->next;
            free((*list));
            *list = temp;
        }
        *list = NULL;
    }
}
