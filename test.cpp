#include "tests.h"

static inline t_ull get_min(Info &info) {
    t_ull v = INF;

    for (t_ull j = 0; j < info.size; ++j)
        if (info.visited[j] == false && (v == INF || info.distances[j] < info.distances[v]))
            v = j;
    return v;
}

static inline void check_distance(Info &info, t_ull v, t_ull j) {
    t_ull to = info.graph[v][j].first;
    t_ull len = info.graph[v][j].second;

    if (info.distances[v] + len <= info.distances[to]) {
        if (info.distances[v] + len < info.distances[to]) {
            info.parents[to].clear();
            info.distances[to] = info.distances[v] + len;
        }
        info.parents[to].push_back(v);
    }
}

void dijkstra(Info &info) {
    for (t_ull i = 0, v; i < info.size; ++i) {
        v = get_min(info);
        if (info.distances[v] == INF)
            break;

        info.visited[v] = true;
        for (t_ull j = 0, size = info.graph[v].size(); j < size; ++j)
            check_distance(info, v, j);
    }
}

static void add_route(Info &info, vector<t_ull> &route, t_ull start) {
    for (size_t i = 0; i < info.parents[route.back()].size(); ++i) {
        route.push_back(info.parents[route.back()][i]);

        if (start != route.back())
            add_route(info, route, start);
        else
            info.routes.push_back(vector<t_ull>(route));

        route.pop_back();
    }
}

// true if left element smaller than right
static bool compare(vector<t_ull> &r1, vector<t_ull> &r2) {
    if (r1.back() < r2.back())
        return true;

    if (r1.back() == r2.back()) {
        t_ull stop = (r1.size() < r2.size() ? r1.size() : r2.size());

        for (t_ull i = 1; i < stop; ++i)
            if (r1[i] < r2[i])
                return true;
    }
    return false;
}

void create_routes(Info &info, t_ull start) {
    vector<t_ull> route;

    for (t_ull i = start; i < info.size; ++i) {
        route.push_back(i);
        add_route(info, route, start);
        route.pop_back();
    }

    for (auto &r : info.routes)
        std::reverse(r.begin(), r.end());

    std::sort(info.routes.begin(), info.routes.end(), compare);
}

static void print_route(Info &info, vector<t_ull> &route, ostream &stream) {
    for (auto i = route.begin(), end = --route.end(); i != end; ++i)
        stream << info.names[*i] << " -> ";
    stream << info.names[route.back()] << endl;
}

static void print_distance(Info &info, vector<t_ull> &route, ostream &stream) {
    t_ull dist = 0;

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

int main() {
    // 4
    // Greenland-Bananal,8
    // Fraser-Greenland,10
    // Bananal-Fraser,3
    // Java-Fraser,5

    // Info info(4);
    // test1(info);

    // ======================================== //

    // 5
    // A-B,11
    // A-C,10
    // B-D,5
    // C-D,6
    // C-E,15
    // D-E,4

    // Info info(5);
    // test2(info);

    // ======================================== //

    // 3
    // Blade-Wizard,1
    // Drive-Blade,1
    // Wizard-Drive,1

    Info info(3);
    test3(info);

    // ======================================== //

    // 4
    // One-Two,1
    // Zero-Eight,8
    // Two-Zero,2

    // Info info(4);
    // test4(info);

    // ======================================== //

    // 8
    // Kyiv-Kharkiv,471
    // Nikopol-Kharkiv,340
    // Kyiv-Warsaw,766
    // Kyiv-Paris,2403
    // Kyiv-Prague,1141
    // Kyiv-Singapore,11864
    // Kyiv-Tokyo,11079

    // Info info(8);
    // test5(info);

    // ======================================== //

    // 7
    // Home-BusStop,4
    // BusStop-Work,7
    // Home-Taxi,1
    // Metro-Home,6
    // Taxi-Work,10
    // Work-Gym,2
    // Metro-Work,8
    // Taxi-Gym,12
    // BusStop-Park,18
    // Park-Metro,16

    // Info info(7);
    // test6(info);

    // ======================================== //

    // 13
    // A-B,1
    // A-C,1
    // A-D,1
    // B-C,1
    // B-E,1
    // B-F,1
    // B-G,1
    // C-D,1
    // C-F,1
    // C-G,1
    // C-H,1
    // D-G,1
    // D-H,1
    // D-I,1
    // E-F,1
    // E-J,1
    // F-G,1
    // F-J,1
    // F-K,1
    // G-J,1
    // G-K,1
    // G-L,1
    // G-H,1
    // H-K,1
    // H-L,1
    // H-I,1
    // I-L,1
    // J-K,1
    // J-M,1
    // K-M,1
    // K-L,1
    // M-L,1

    // Info info(13);
    // test7(info);

    // ======================================== //

    // 17
    // A-B,2
    // A-C,2
    // A-D,2
    // B-C,2
    // B-E,1
    // C-D,2
    // C-E,1
    // C-F,1
    // B-G,2
    // B-H,2
    // C-I,2
    // D-F,1
    // D-J,2
    // D-K,2
    // E-H,1
    // E-I,1
    // F-I,1
    // F-J,1
    // H-L,1
    // J-M,1
    // G-H,2
    // G-N,2
    // H-I,2
    // H-N,2
    // I-L,1
    // I-O,2
    // I-M,1
    // I-J,2
    // J-K,2
    // J-P,2
    // K-P,2
    // L-N,1
    // L-O,1
    // M-O,1
    // M-P,1
    // N-O,2
    // N-Q,2
    // O-P,2
    // O-Q,2
    // P-Q,2

    // Info info(17);
    // test8(info);

    // ======================================== //

    // 12
    // Seattle-SanFrancisco,1306
    // SanFrancisco-LasVegas,919
    // SanFrancisco-LosAngeles,629
    // LosAngeles-LasVegas,435
    // Seattle-Denver,2161
    // Seattle-Minneapolis,2661
    // LasVegas-Denver,1225
    // Denver-Dallas,1258
    // Denver-Minneapolis,1483
    // Minneapolis-Dallas,1532
    // LasVegas-Dallas,1983
    // Minneapolis-Chicago,661
    // Chicago-WashDC,1145
    // Chicago-Boston,1613
    // Boston-NewYork,338
    // NewYork-Miami,2145
    // Dallas-WashDC,2113
    // Dallas-Miami,2161
    // WashDC-Miami,1709
    // WashDC-NewYork,383
    // WashDC-Boston,725

    // Info info(12);
    // test9(info);

    // ======================================== //

    std::ofstream ofile("result.txt");

    for (size_t i = 0; i < info.size - 1; ++i) {
        info.distances[i] = 0;
        dijkstra(info);

        create_routes(info, i);
        // print_routes(info, cout);
        print_routes(info, ofile);

        clean_info(info);
    }
    ofile.close();
}
