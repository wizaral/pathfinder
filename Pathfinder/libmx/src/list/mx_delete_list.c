#include "libmx.h"

void mx_delete_list(t_list *list) {
    if (list) {
        mx_clear_list(list);
        if (malloc_size(list))
            free(list);
    }
}
