#include "libmx.h"

t_flist *mx_fsort_list(t_flist *list, int (*cmp)(const void *, const void *)) {
    // mergesort lol

    return list && cmp ? list : NULL;
}
