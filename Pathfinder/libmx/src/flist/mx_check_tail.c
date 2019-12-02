#include "libmx.h"

t_list_node *mx_check_tail(t_list *list) {
    t_list_node *tail = list ? list->head : NULL;

    for (; tail && tail->next; tail = tail->next);
    return list ? list->tail = tail : NULL;
}
