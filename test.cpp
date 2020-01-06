#include "tests.h"

static inline ull get_min(Info &info) {
    ull v = INF;

    for (ull j = 0; j < info.size; ++j)
        if (info.visited[j] == false && (v == INF || info.distances[j] < info.distances[v]))
            v = j;
    return v;
}

static inline void check_distance(Info &info, ull v, ull j) {
    ull to = info.graph[v][j].first;
    ull len = info.graph[v][j].second;

    if (info.distances[v] + len <= info.distances[to]) {
        if (info.distances[v] + len < info.distances[to]) {
            info.parents[to].clear();
            info.distances[to] = info.distances[v] + len;
        }
        info.parents[to].push_back(v);
    }
}

static inline void dijkstra(Info &info) {
    for (ull i = 0, v; i < info.size; ++i) {
        v = get_min(info);
        if (info.distances[v] == INF)
            break;

        info.visited[v] = true;
        for (ull j = 0, size = info.graph[v].size(); j < size; ++j)
            check_distance(info, v, j);
    }
}

static inline void add_route(Info &info, vector<ull> &route) {
    for (size_t i = 0; i < info.parents[route.back()].size(); ++i) {
        route.push_back(info.parents[route.back()][i]);

        if (info.start != route.back())
            add_route(info, route);
        else
            info.routes.push_back(vector<ull>(route));

        route.pop_back();
    }
}

// true if left element smaller than right
static inline bool compare(vector<ull> &r1, vector<ull> &r2) {
    if (r1.back() < r2.back())
        return true;

    if (r1.back() == r2.back()) {
        ull stop = (r1.size() < r2.size() ? r1.size() : r2.size());

        for (ull i = 1; i < stop; ++i)
            if (r1[i] != r2[i])
                return r1[i] < r2[i];
    }
    return false;
}

static inline void create_routes(Info &info) {
    vector<ull> route;

    for (ull i = info.start + 1; i < info.size; ++i) {
        route.push_back(i);
        add_route(info, route);
        route.pop_back();
    }

    for (auto &r : info.routes)
        std::reverse(r.begin(), r.end());

    std::sort(info.routes.begin(), info.routes.end(), compare);
}

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

static inline void print_routes(Info &info) {
    const static std::string delim(40, '=');

    for (auto r = info.routes.begin(), end = info.routes.end(); r != end; ++r) {
        cout << delim << endl;
        cout << "Path: " << info.names[(*r).front()] << " -> ";
        cout << info.names[(*r).back()] << endl;

        cout << "Route: ";
        print_route(info, (*r));

        cout << "Distance: ";
        if ((*r).size() > 2)
            print_distance(info, (*r));
        else
            cout << info.distances[(*r).back()] << endl;

        cout << delim << endl;
    }
}

static inline void clean_info(Info &info) {
    for (auto &p : info.parents)
        p.clear();

    for (auto &r : info.routes)
        r.clear();

    info.routes.clear();
    info.distances.assign(info.size, INF);
    info.visited.assign(info.size, false);
}

static inline void test(Info &info) {
    for (size_t i = 0; i < info.size - 1; ++i) {
        info.distances[i] = 0;
        info.start = i;
        dijkstra(info);

        create_routes(info);
        print_routes(info);
        clean_info(info);
    }
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int testtype = std::stoi(argv[1]);

        switch (testtype) {
        case 1: {
            Info info(4);
            test1(info);
            test(info);
            break;
        }
        case 2: {
            Info info(5);
            test2(info);
            test(info);
            break;
        }
        case 3: {
            Info info(3);
            test3(info);
            test(info);
            break;
        }
        case 4: {
            Info info(3);
            test4(info);
            test(info);
            break;
        }
        case 5: {
            Info info(4);
            test5(info);
            test(info);
            break;
        }
        case 6: {
            Info info(8);
            test6(info);
            test(info);
            break;
        }
        case 7: {
            Info info(7);
            test7(info);
            test(info);
            break;
        }
        case 8: {
            Info info(13);
            test8(info);
            test(info);
            break;
        }
        case 9: {
            Info info(17);
            test9(info);
            test(info);
            break;
        }
        case 10: {
            Info info(49);
            test10(info);
            test(info);
            break;
        }
        default:
            cout << "Wrong number!" << endl;
        }
    }
    else
        cout << "usage: ./pathfinder [testnumber]" << endl;
}
