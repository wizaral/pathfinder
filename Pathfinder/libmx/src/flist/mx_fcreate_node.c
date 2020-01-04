#include "libmx.h"

t_flist_node *mx_fcreate_node(void *data, t_flist_node *next) {
    t_flist_node *node = (t_flist_node *)malloc(sizeof(t_flist_node));

    if (node) {
        node->data = data;
        node->next = next;
    }
    return node;
}
