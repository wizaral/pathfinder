#ifndef FLIST_H
#define FLIST_H

#include "types.h"

typedef struct s_flist_node {
    void *data;
    struct s_flist_node *next;
} t_flist_node;

typedef struct s_flist {
    t_ll size;          // amount of elements
    t_flist_node *head; // first element
    t_flist_node *tail; // last element
} t_flist;

/*
* deletes cycle
* counts elements in list and rewrite size
* checks every element and rewrite tail
*/

void mx_fcheck_cycle(t_flist *list);
t_ll mx_fcheck_size(t_flist *list);
t_flist_node *mx_fcheck_tail(t_flist *list);

/*
* creates base struct
* deletes base struct and all elements
*/

t_flist *mx_fcreate_list();
void mx_fdelete_list(t_flist **list);

/*
* creates node struct and assigns next element
* delete all elements from list
*/

t_flist_node *mx_fcreate_node(void *data, t_flist_node *next);
void mx_fclear_list(t_flist *list);

/*
* deletes first element
* deletes last element
* deletes element with pos index
*/

void mx_fpop_back(t_flist *list);
void mx_fpop_front(t_flist *list);
void mx_fpop_index(t_flist *list, t_ll pos);

/*
* adds first element
* adds last element
* adds element with in pos index
*/

void mx_fpush_back(t_flist *list, void *data);
void mx_fpush_front(t_flist *list, void *data);
void mx_fpush_index(t_flist *list, void *data, t_ll pos);

/*
* sorts elements in list
* returns null-terminated array of data pointers
* applies function f to every element in the container
*/

t_flist *mx_fsort_flist(t_flist *list, int (*cmp)(const void *, const void *));
void **mx_flist_to_array(t_flist *list);
void mx_fforeach_list(t_flist *list, void (*f)(t_flist_node *));

#endif
