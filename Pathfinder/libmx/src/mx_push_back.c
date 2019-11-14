#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new_node = NULL;
    t_list *temp = NULL;

    if (list && (new_node = mx_create_node(data)) != NULL) {
        if (*list) {
            temp = *list;

            while (temp->next)
                temp = temp->next;

            temp->next = new_node;
        }
        else
            *list = new_node;
    }
}
