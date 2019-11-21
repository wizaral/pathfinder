#ifndef STACK_H
#define STACK_H

#include "types.h"

typedef struct s_stack {
    t_ull cap;      // capacity
    t_ull size;     // current size
    size_t bytes;   // size of item
    void *arr;      // array of items
} t_stack;

t_stack *mx_create_stack(size_t bytes);  // create base struct
void mx_delete_stack(t_stack **st);      // delete base struct

void mx_push(t_stack *st, void *item);   // add element at the end
void *mx_top(t_stack *st);               // return pointer on last item
void *mx_pop(t_stack *st);               // delete last item

void mx_foreach_stack(t_stack *st, void (*f)(void *));

#endif
