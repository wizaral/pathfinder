#ifndef GRAPH_H
#define GRAPH_H

#define INF 2147483647

#include "libmx.h"

typedef struct s_info {
    t_vector graph;     // vector<vector<pair<ull, ull>>>
    t_vector parents;   // vector<vector<ull>>
    t_vector routes;    // vector<vector<ull>>
    t_vector distances; // vector<ull>
    t_vector visited;   // vector<char>
    t_vector names;     // vector<string>
    size_t start;       // entry point to graph
    size_t size;        // amount of dots
} t_info;

typedef struct s_pair {
    unsigned long long island;
    unsigned long long distance;
} t_pair;

// t_info info = {{}, {}, {}, {}, {}, {}, 0, size};

#endif
