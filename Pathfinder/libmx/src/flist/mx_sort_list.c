#include "libmx.h"

t_list *mx_sort_list(t_list *list, int (*cmp)(const void *, const void *)) {
    int swaps = 0;

    for (t_list_node *node1 = list; node1 && cmp; node1 = node1->next) {
        for (t_list_node *node2 = list; node2->next; node2 = node2->next)
            if (cmp(node2->data, node2->next->data) > 0)
                mx_swap_void(&node2->data, &node2->next->data), ++swaps;
        if (swaps == 0)
            break;
    }
    return list;
}
