#ifndef TREE_H
#define TREE_H

#include "types.h"

#define TREE_DEFAULT_SIZE 16

typedef struct s_tree_node {
    void *data;
    struct s_tree_node *next;
    struct s_tree_node *prev;
} t_tree_node;

typedef struct s_tree {
    size_t size;
    t_tree_node *root;
    int (*cmp)(const void *, const void *);
} t_tree;



#endif
