#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

typedef struct s_queue {
    t_ull cap;      // capacity
    t_ull size;     // current size

    t_ull head;     // position of first element // front
    t_ull tail;     // position of last element // rear

    size_t bytes;   // sie of item
    void *arr;      // array of items
} t_queue;

/*
* creates base struct
* deletes base struct
*/

t_queue *mx_create_queue(size_t bytes);
void mx_delete_queue(t_queue **q);

/*
* adds element at the end
* deletes first element
*/

void mx_enqueue(t_queue *q, void *item);
void *mx_dequeue(t_queue *q);

/*
* returns first element
* returns last element
*/

void *mx_front(t_queue *q);
void *mx_rear(t_queue *q);

/*
* applies function f to every element in the container
*/

void mx_foreach_queue(t_queue *q, void (*f)(void *));

#endif
