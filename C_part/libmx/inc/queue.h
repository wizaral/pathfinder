#pragma once

#define QUEUE_DEFAULT_SIZE 16

typedef struct s_queue {
    size_t cap;     // capacity
    size_t size;    // current size

    size_t head;    // position of first element // front
    size_t tail;    // position of last element // rear

    size_t bytes;   // sie of item
    uint8_t *arr;    // array of items
} t_queue;

/*
* creates base struct
* deletes base struct
*/

t_queue *mx_create_queue(size_t bytes);
void mx_delete_queue(t_queue *q);

/*
* adds element at the end
* deletes first element and returns it
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
* erases all elements from the container
* applies function f to every element in the container
*/

void mx_clear_queue(t_queue *q);
void mx_foreach_queue(t_queue *q, void (*f)(void *));
