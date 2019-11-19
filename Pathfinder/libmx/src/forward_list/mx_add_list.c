#include "libmx.h"

void mx_add_list(t_list *dst, t_list *src, t_ll index) {
    t_list_node *node = dst && src ? src->head : NULL;

    if (dst && src && dst->head == NULL && dst->tail == NULL) {
        dst->head = dst->tail = src->head;
        dst->size = src->size;
    }
    else {
        // вставка второго списка в первый ...
    }
}
