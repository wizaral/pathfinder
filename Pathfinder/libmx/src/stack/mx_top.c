#include "libmx.h"

void *mx_top(t_stack *stack) {
    return stack && stack->array ?
        (unsigned char)stack->array + (stack->bytes * (stack->size - 1)) :
        NULL;
}
