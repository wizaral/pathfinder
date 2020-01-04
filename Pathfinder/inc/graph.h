#ifndef GRAPH_H
#define GRAPH_H

#define INF 2147483647

#include "libmx.h"

typedef struct s_info {
    t_vector graph;     // vector<vector<pair<size_t, size_t>>>
    t_vector parents;   // vector<vector<size_t>>
    t_vector routes;    // vector<vector<size_t>>
    t_vector distances; // vector<size_t>
    t_vector visited;   // vector<char>
    t_vector names;     // vector<string>
    size_t start;       // entry point to graph
    size_t size;        // amount of dots
} t_info;

typedef struct s_pair {
    size_t island;
    size_t distance;
} t_pair;

#endif
