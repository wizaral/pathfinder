#include "libmx.h"

int mx_list_size(t_list *list) {
    int size = 0;

    for (; list; list = list->next, ++size);
    return size;
}
