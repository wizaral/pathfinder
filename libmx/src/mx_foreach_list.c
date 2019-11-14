#include "libmx.h"

void mx_foreach_list(t_list *list, void (*f)(t_list *)) {
    for (; f && list; list = list->next)
        f(list);
}
