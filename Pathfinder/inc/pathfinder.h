#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "graph.h"
#include "error.h"

/*
* dijkstra algorithm for searching shortests pathes
* creates routes from array of arrays of parents and sorts in FIFO order
* prints all routes from the current island to other
*/

void mx_algorithm(t_info *info);
void mx_create_routes(t_info *info);
void mx_print_routes(t_info *info);
void mx_sort_routes(t_vector *routes);

/*
* creating t_info struct before first iteration of algorithm
* cleaning t_info struct for next iteration of algorithm
* deleting t_info struct after last iteration of algorithm
*/

void mx_init_info(t_info *info, size_t size);
void mx_clear_info(t_info *info);
void mx_delete_info(t_info *info);

/*
* returns value in first line or 0 in invalid cases
*/

int mx_check_file(const char *filename);

#endif
