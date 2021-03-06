#pragma once

#include "libmx.h"
#define MX_INF 2147483647

typedef struct s_info {
    t_vector *graph;    // array<vector<pair<size_t, int>>>
    t_vector *parents;  // array<vector<size_t>>
    char **names;       // array<string>
    char *visited;      // array<char>
    int *distances;     // array<int>
    t_vector routes;    // vector<vector<size_t>>
    size_t start;       // entry point to graph
    size_t size;        // amount of dots
} t_info;

typedef struct s_pair {
    size_t island;      // number of connected island
    int distance;       // distance to island
} t_pair;
