#ifndef STACK_H
#define STACK_H

#include "types.h"

typedef struct s_stack {
    t_ull cap;      // capacity
    t_ull size;     // current size
    size_t bytes;   // size of item
    void *arr;      // array of items
} t_stack;

/*
* creates base struct
* deletes base struct
*/

t_stack *mx_create_stack(size_t bytes);
void mx_delete_stack(t_stack **st);

/*
* adds element at the end
* returns pointer on last item
* removes last item and return its pointer
*/

void mx_push(t_stack *st, void *item);
void *mx_top(t_stack *st);
void *mx_pop(t_stack *st);

/*
* applies function f to every element of the container
*/

void mx_foreach_stack(t_stack *st, void (*f)(void *));

#endif
