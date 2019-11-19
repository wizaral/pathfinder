#include "libmx.h"

void mx_delete_list(t_list **list) {
    if (list && *list) {
        mx_clear_list(*list);
        free(*list);
        *list = NULL;
    }
}
