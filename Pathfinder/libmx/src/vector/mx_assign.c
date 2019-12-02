#include "libmx.h"

void mx_assign(t_vector *v, size_t count, const void *item) {
    for (size_t i = 0; i < count; ++i)
        mx_push_backward(v, item);
}
