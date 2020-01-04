#include "libmx.h"

void mx_assign_vector(t_vector *v, size_t count, const void *item) {
    mx_clear_vector(v);
    for (size_t i = 0; i < count; ++i)
        mx_push_backward(v, item);
}
