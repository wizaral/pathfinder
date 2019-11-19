#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

typedef struct s_vector {
    long long capacity;
    long long size;
    size_t bytes;
    void *array;
} t_vector;

t_vector *mx_create_stack();
void mx_delete_stack(t_vector **vector);

void mx_push_back(t_vector *vector, void *item);
void mx_pop_back(t_vector *vector);
void *mx_front(t_vector *vector);
void *mx_back(t_vector *vector);

void mx_foreach_vector(t_vector *vector, void (*f)(void *));

#endif
