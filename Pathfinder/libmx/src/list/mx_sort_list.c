#include "libmx.h"

t_list *mx_sort_list(t_list *list, int (*cmp)(const void *, const void *)) {
// mergesort lol

    return list && cmp ? list : NULL;
}
