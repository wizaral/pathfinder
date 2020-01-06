#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "graph.h"
#include "error.h"

/*
* dijkstra algorithm for searching shortests pathes
* creating routes from array of arrays of parents and sorting in FIFO order
* printing all routes from current island to others
* cleaning t_info struct for next iteration of algorithm
*/

void mx_algorithm(t_info *info);
void mx_create_routes(t_info *info);
void mx_print_routes(t_info *info);
void mx_clear_info(t_info *info);
void mx_delete_info(t_info *info);

#endif
