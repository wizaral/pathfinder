#include "libmx.h"

void mx_push(t_stack *stack, void *item) {
    if (stack && stack->array && item) {
        if (stack->size == stack->capacity) {
            stack->capacity *= 1.5;
            stack->array = mx_realloc(stack->array, stack->capacity);
        }

        mx_memcpy((unsigned char)stack->array + (stack->size * stack->bytes),
            item, stack->bytes);
        ++stack->size;
    }
}
