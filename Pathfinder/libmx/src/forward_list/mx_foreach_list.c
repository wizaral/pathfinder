#include "libmx.h"

void mx_foreach_list(t_list *list, void (*f)(t_list_node *)) {
    t_list_node *node = list ? list->head : NULL;

    if (f && list)
        for (; node; node = node->next)
            f(node);
}
