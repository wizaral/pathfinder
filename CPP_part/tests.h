#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#define INF 2147483647
using ull = unsigned long long;
using std::vector, std::pair, std::cout, std::endl;

struct Info {
    Info(ull size)
        : graph(vector<vector<pair<ull, ull>>>(size, vector<pair<ull, ull>>())),
        parents(vector<vector<ull>>(size)),
        routes(vector<vector<ull>>()),
        distances(vector<ull>(size, INF)),
        visited(vector<char>(size, false)),
        names(vector<std::string>(size)),
        start(0),
        size(size) {}

    vector<vector<pair<ull, ull>>> graph;
    vector<vector<ull>> parents;
    vector<vector<ull>> routes;
    vector<ull> distances;
    vector<char> visited;
    vector<std::string> names;
    ull start;
    ull size;
};
