#include "libmx.h"

void *mx_pop(t_stack *stack) {
    void *item = mx_peek(stack);

    if (stack && stack->array) {
        --stack->size;

        if ((float)stack->capacity / stack->size > 3 && stack->capacity > 30) {
            stack->capacity = stack->capacity / 3 + 1;
            stack->array = mx_realloc(stack->array, stack->capacity);
        }
    }
    return item;
}
