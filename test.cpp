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

void dijkstra(Info &info) {
    for (ull i = 0, v; i < info.size; ++i) {
        v = get_min(info);
        if (info.distances[v] == INF)
            break;

        info.visited[v] = true;
        for (ull j = 0, size = info.graph[v].size(); j < size; ++j)
            check_distance(info, v, j);
    }
}

static void add_route(Info &info, vector<ull> &route, ull start) {
    for (size_t i = 0; i < info.parents[route.back()].size(); ++i) {
        route.push_back(info.parents[route.back()][i]);

        if (start != route.back())
            add_route(info, route, start);
        else
            info.routes.push_back(vector<ull>(route));

        route.pop_back();
    }
}

// true if left element smaller than right
static bool compare(vector<ull> &r1, vector<ull> &r2) {
    if (r1.back() < r2.back())
        return true;

    if (r1.back() == r2.back()) {
        ull stop = (r1.size() < r2.size() ? r1.size() : r2.size());

        for (ull i = 1; i < stop; ++i)
            if (r1[i] < r2[i])
                return true;
    }
    return false;
}

void create_routes(Info &info, ull start) {
    vector<ull> route;

    for (ull i = start; i < info.size; ++i) {
        route.push_back(i);
        add_route(info, route, start);
        route.pop_back();
    }

    for (auto &r : info.routes)
        std::reverse(r.begin(), r.end());

    std::sort(info.routes.begin(), info.routes.end(), compare);
}

static void print_route(Info &info, vector<ull> &route, std::ostream &stream) {
    for (auto i = route.begin(), end = --route.end(); i != end; ++i)
        stream << info.names[*i] << " -> ";
    stream << info.names[route.back()] << endl;
}

static inline void print_distance(Info &info, vector<ull> &route, std::ostream &stream) {
    ull dist = 0;

    for (auto i = ++route.begin(), end = --route.end(); i != end; ++i) {
        stream << info.distances[*i] - dist << " + ";
        dist = info.distances[*i];
    }
    stream << info.distances[*(--route.end())] - dist
        << " = " << info.distances[route.back()] << endl;
}

void print_routes(Info &info, std::ostream &stream) {
    const static std::string delim(40, '=');

    for (auto r = info.routes.begin(), end = info.routes.end(); r != end; ++r) {
        stream << delim << endl;
        stream << "Path: " << info.names[(*r).front()] << " -> ";
        stream << info.names[(*r).back()] << endl;

        stream << "Route: ";
        print_route(info, (*r), stream);

        stream << "Distance: ";
        if ((*r).size() > 2)
            print_distance(info, (*r), stream);
        else
            stream << info.distances[(*r).back()] << endl;

        stream << delim << endl;
    }
}

void clean_info(Info &info) {
    for (auto &p : info.parents)
        p.clear();

    info.routes.clear();
    info.distances.assign(info.size, INF);
    info.visited.assign(info.size, false);
}

void test(Info &info, std::ostream &stream) {
    for (size_t i = 0; i < info.size - 1; ++i) {
        info.distances[i] = 0;
        dijkstra(info);

        create_routes(info, i);
        print_routes(info, stream);

        clean_info(info);
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int testtype = std::stoi(argv[1]);
        std::ofstream file(argc > 2 ? std::ofstream(argv[2]) : std::ofstream());
        std::ostream stream(argc > 2 ? std::ostream(file.rdbuf()) : std::ostream(cout.rdbuf()));

        switch (testtype) {
        case 1: {
            Info info(4);
            test1(info);
            test(info, stream);
            break;
        }
        case 2: {
            Info info(5);
            test2(info);
            test(info, stream);
            break;
        }
        case 3: {
            Info info(3);
            test3(info);
            test(info, stream);
            break;
        }
        case 4: {
            Info info(3);
            test4(info);
            test(info, stream);
            break;
        }
        case 5: {
            Info info(4);
            test5(info);
            test(info, stream);
            break;
        }
        case 6: {
            Info info(8);
            test6(info);
            test(info, stream);
            break;
        }
        case 7: {
            Info info(7);
            test7(info);
            test(info, stream);
            break;
        }
        case 8: {
            Info info(13);
            test8(info);
            test(info, stream);
            break;
        }
        case 9: {
            Info info(17);
            test9(info);
            test(info, stream);
            break;
        }
        case 10: {
            Info info(12);
            test10(info);
            test(info, stream);
            break;
        }
        }
        file.close();
    }
    else
        cout << "usage: ./pathfinder [testnumber] [filename]" << endl;
}
