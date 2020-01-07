#ifndef STACK_H
#define STACK_H

#include "types.h"

#define STACK_DEFAULT_SIZE 16

typedef struct s_stack {
    size_t cap;     // capacity
    size_t size;    // current size
    size_t bytes;   // size of item
    t_byte *arr;    // array of items
} t_stack;

/*
* creates base struct
* deletes base struct
*/

t_stack *mx_create_stack(size_t bytes);
void mx_delete_stack(t_stack *st);

/*
* adds element at the end
* removes last item and return its pointer
* returns pointer on last item
*/

void mx_push(t_stack *st, void *item);
void *mx_pop(t_stack *st);
void *mx_top(t_stack *st);

/*
* erases all elements from the container
* applies function f to every element of the container
*/

void mx_clear_stack(t_stack *st);
void mx_foreach_stack(t_stack *st, void (*f)(void *));

#endif
