#ifndef STACK_H
#define STACK_H

#include "types.h"

typedef struct s_stack {
    long long capacity;
    long long size;
    size_t bytes;
    void *array;
} t_stack;

t_stack *mx_create_stack(size_t bytes);     // создание управляющей структуры
void mx_delete_stack(t_stack **stack);      // удаление структуры и массива

void mx_push(t_stack *stack, void *item);   // добавление в конец
void *mx_top(t_stack *stack);               // указатель на верхний элемент
void *mx_pop(t_stack *stack);               // удаление с конца

void mx_foreach_stack(t_stack *stack, void (*f)(void *));

#endif
