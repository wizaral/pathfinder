#include "libmx.h"

void mx_fforeach_list(t_flist *list, void (*f)(t_flist_node *)) {
    t_flist_node *node = f && list ? list->head : NULL;

    for (; node; node = node->next)
        f(node);
}
