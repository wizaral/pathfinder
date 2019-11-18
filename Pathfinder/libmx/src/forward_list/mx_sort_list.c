#include "libmx.h"

t_forward_list *mx_sort_list(t_forward_list *list, bool (*cmp)(void *a, void *b)) {
    int swaps = 0;

    for (t_list_node *node1 = list; node1 && cmp; node1 = node1->next) {
        for (t_list_node *node2 = list; node2->next; node2 = node2->next)
            if (cmp(node2->data, node2->next->data))
                mx_swap_void(&node2->data, &node2->next->data), ++swaps;
        if (swaps == 0)
            break;
    }
    return list;
}
