#include "libmx.h"

t_stack *mx_create_stack(size_t bytes) {
    t_stack *stack = bytes > 0 ? (t_stack *)malloc(sizeof(t_stack)) : NULL;

    if (stack) {
        stack->capacity = 10;
        stack->size = 0;
        stack->bytes = bytes;
        stack->array = malloc(bytes * stack->capacity);
    }
    return stack;
}
