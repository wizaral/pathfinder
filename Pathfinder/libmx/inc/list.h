#ifndef LIST_H
#define LIST_H

#include "types.h"

typedef struct s_list_node {
    void *data;
    struct s_list_node *next;
    struct s_list_node *prev;
} t_list_node;

typedef struct s_list {
    size_t size;        // amount of elements
    t_list_node *head;  // first element
    t_list_node *tail;  // last element
} t_list;

/*
* creates base struct
* deletes base struct and all elements
*/

t_list *mx_create_list(void);
void mx_delete_list(t_list *list);

/*
* creates node struct and assigns next element
* delete all elements from list
*/

t_list_node *mx_create_node(void *data, t_list_node *prev, t_list_node *next);
void mx_clear_list(t_list *list);

/*
* deletes first element
* deletes last element
* deletes element with pos index
*/

void mx_pop_back(t_list *list);
void mx_pop_front(t_list *list);
void mx_pop_index(t_list *list, size_t pos);

/*
* adds first element
* adds last element
* adds element with in pos index
*/

void mx_push_back(t_list *list, void *data);
void mx_push_front(t_list *list, void *data);
void mx_push_index(t_list *list, void *data, size_t pos);

/*
* sorts elements in list
* returns null-terminated array of data pointers
* applies function to every element in the container in ascending order
* applies function to every element in the container in descending order
*/

t_list *mx_sort_list(t_list *list, int (*cmp)(const void *, const void *));
void **mx_list_to_array(t_list *list);
void mx_foreach_list(t_list *list, void (*f)(t_list_node *));
void mx_foreach_list_reverse(t_list *list, void (*f)(t_list_node *));

#endif
