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

t_queue *mx_create_queue(size_t bytes);     // create base struct
void mx_delete_queue(t_queue **q);          // delete base struct

void mx_enqueue(t_queue *q, void *item);    // add element at the end
void *mx_dequeue(t_queue *q);               // delete first element
void *mx_front(t_queue *q);                 // return first element
void *mx_rear(t_queue *q);                  // return element at the end

void mx_realloc_queue(t_queue *q, double scale);
void mx_foreach_queue(t_queue *q, void (*f)(void *));

#endif
