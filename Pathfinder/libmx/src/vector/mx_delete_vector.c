#include "libmx.h"

void mx_delete_vector(t_vector *v) {
    if (v) {
        if (malloc_size(v->arr))
            free(v->arr);
        if (malloc_size(v))
            free(v);
    }
}
