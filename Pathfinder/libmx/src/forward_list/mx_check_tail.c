#include "libmx.h"

long long mx_check_tail(t_forward_list *list) {
    t_list_node *tail = list ? list->head : NULL;

    for (; tail && tail->next; tail = tail->next);
    return list ? list->tail = tail : NULL;
}
