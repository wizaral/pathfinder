#include "libmx.h"

void mx_delete_stack(t_stack **stack) {
    if (stack && *stack) {
        if (malloc_size((*stack)->array))
            free((*stack)->array);
        if (malloc_size(*stack))
            free(*stack);
        *stack = NULL;
    }
}
