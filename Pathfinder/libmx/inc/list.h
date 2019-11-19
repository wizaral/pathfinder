#ifndef LIST_H
#define LIST_H

#include "types.h"

typedef struct s_list_node {
    void *data;
    struct s_list_node *next;
} t_list_node;

typedef struct s_list {
    t_ll size;
    t_list_node *head;
    t_list_node *tail;
} t_list;

void mx_check_cycle(t_list *list);          // проверка цикла методом зайца-черепашки
t_ll mx_check_size(t_list *list);           // проход по листу + перезапись размера
t_list_node *mx_check_tail(t_list *list);   // проход по листу + перезапись хвоста

t_list_node *mx_create_node(void *data, t_list_node *next); // создание ноды списка
void mx_clear_list(t_list *list);                   // удаление всех нод
void mx_delete_list(t_list **list);                 // удаление всех нод и хранящей структуры

void mx_foreach_list(t_list *list, void (*f)(t_list_node *));

void mx_pop_back(t_list *list);                     // удаление хвоста
void mx_pop_front(t_list *list);                    // удаление головы
void mx_pop_index(t_list *list, t_ll index);        // удаление по номеру

void mx_push_back(t_list *list, void *data);                // вставка в конец
void mx_push_front(t_list *list, void *data);               // вставка в начало
void mx_push_index(t_list *list, void *data, t_ll index);   // вставка по индексу

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *));    // bubble

// создает массив указателей на информацию из нод списка
void **mx_list_to_array(t_list *list);
// добавляет элементы списка src в список dst начиная с индекса
void mx_add_list(t_list *dst, t_list *src, t_ll index);

#endif
