#include "libmx.h"

void mx_foreach_stack(t_stack *stack, void (*f)(void *)) {
    if (stack && stack->array && f)
        for (long long i = 0; i < stack->size; ++i)
            f((unsigned char)stack->array + (stack->bytes * i));
}
