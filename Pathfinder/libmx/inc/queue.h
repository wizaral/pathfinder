#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

typedef struct s_queue {
    long long capacity;
    long long size;

    long long pointer1;
    long long pointer2;

    size_t bytes;
    void *array;
} t_queue;

t_queue *mx_create_queue(size_t bytes);
void mx_delete_queue(t_queue **queue);

void mx_enqueue(t_queue *queue, void *item);
void mx_dequeue(t_queue *queue);
void *mx_front(t_queue *queue);
void *mx_rear(t_queue *queue);

void mx_foreach_queue(t_queue *queue, void (*f)(void *));

#endif
