#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

typedef struct s_vector {
    t_ull cap;      // capacity
    t_ull size;     // current size
    size_t bytes;   // size of item
    void *arr;      // array of items
} t_vector;

t_vector *mx_create_vector(size_t bytes);  // create base struct
void mx_delete_vector(t_vector **v);      // delete base struct

// replaces the contents of container with count copies of value item
void mx_assign(t_vector *v, size_t count, void *item);

void mx_push_backward(t_vector *v, void *item); // add element to the end of container
void *mx_pop_backward(t_vector *v);             // delete last item of the container

// returns a pointer to the element at specified location pos, with bounds checking
void *mx_at(t_vector *v, t_ull pos);
void *mx_get_front(t_vector *v);    // returns a pointer to the first element in the container
void *mx_get_back(t_vector *v);     // returns a pointer to the last element in the container

void mx_foreach_vector(t_vector *st, void (*f)(void *));


#endif
