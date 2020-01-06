#ifndef GRAPH_H
#define GRAPH_H

#define MX_INT_MAX 2147483647
#define MX_INF 18446744073709551615ULL

#include "libmx.h"

typedef struct s_info {
    t_vector graph;     // vector<vector<pair<size_t, t_i64>>>
    t_vector parents;   // vector<vector<size_t>>
    t_vector routes;    // vector<vector<size_t>>
    t_vector distances; // vector<t_i64>
    t_vector visited;   // vector<char>
    t_vector names;     // vector<string>
    size_t start;       // entry point to graph
    size_t size;        // amount of dots
} t_info;

typedef struct s_pair {
    size_t island;
    t_i64 dist;
} t_pair;

#endif
