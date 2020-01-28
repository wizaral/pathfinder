#include "pathfinder.h"

static inline void print_route(Info &info, vector<ull> &route) {
    for (auto i = route.begin(), end = --route.end(); i != end; ++i)
        cout << info.names[*i] << " -> ";
    cout << info.names[route.back()] << endl;
}

static inline void print_distance(Info &info, vector<ull> &route) {
    ull dist = 0;

    for (auto i = ++route.begin(), end = --route.end(); i != end; ++i) {
        cout << info.distances[*i] - dist << " + ";
        dist = info.distances[*i];
    }
    cout << info.distances[*(--route.end())] - dist
        << " = " << info.distances[route.back()] << endl;
}

void print_routes(Info &info) {
    for (auto r = info.routes.begin(), end = info.routes.end(); r != end; ++r) {
        cout << "========================================" << endl;
        cout << "Path: " << info.names[(*r).front()] << " -> ";
        cout << info.names[(*r).back()] << endl;

        // cout << info.names[(*r).front()] << "-";
        // cout << info.names[(*r).back()] << ",";
        // cout << info.distances[(*r).back()] << endl;

        cout << "Route: ";
        print_route(info, (*r));

        cout << "Distance: ";
        if ((*r).size() > 2)
            print_distance(info, (*r));
        else
            cout << info.distances[(*r).back()] << endl;

        cout << "========================================" << endl;
    }
}
