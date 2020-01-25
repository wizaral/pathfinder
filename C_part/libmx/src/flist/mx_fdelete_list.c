#include "libmx.h"

void mx_fdelete_list(t_flist *list) {
    if (list) {
        mx_fclear_list(list);
        if (MX_MALLOC_SIZE(list))
            free(list);
    }
}
