#include "tests.h"

static inline ull get_min(Info &info) {
    ull visited = INF;

    for (ull j = 0; j < info.size; ++j)
        if (info.visited[j] == false && (visited == INF || info.distances[j] < info.distances[visited]))
            visited = j;
    return visited;
}

static inline void check_distance(Info &info, ull visited, ull j) {
    auto [to, len] = info.graph[visited][j];

    if (info.distances[visited] + len <= info.distances[to]) {
        if (info.distances[visited] + len < info.distances[to]) {
            info.distances[to] = info.distances[visited] + len;
            info.parents[to].clear();
        }
        if (len || info.visited[to] == false)
            info.parents[to].push_back(visited);
    }
}

static inline void dijkstra(Info &info) {
    for (ull i = 0, visited; i < info.size; ++i) {
        if (visited = get_min(info); info.distances[visited] != INF) {
            info.visited[visited] = true;
            for (ull j = 0, size = info.graph[visited].size(); j < size; ++j)
                check_distance(info, visited, j);
        }
    }
}

static void add_route(Info &info, vector<ull> &route) {
    for (size_t i = 0; i < info.parents[route.back()].size(); ++i) {
        route.push_back(info.parents[route.back()][i]);

        if (info.start != route.back())
            add_route(info, route);
        else
            info.routes.emplace_back(vector<ull>(route));

        route.pop_back();
    }
}

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

    // info.routes.erase(std::unique(info.routes.begin(), info.routes.end(),
    // [](vector<ull> &v1, vector<ull> &v2) {
    //     return v1.back() == v2.back();
    // }), info.routes.end());
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

static inline void clean_info(Info &info) {
    for (auto &r : info.routes)
        r.clear();
    info.routes.clear();

    for (size_t i = 0; i < info.size; ++i) {
        info.distances[i] = INF;
        info.visited[i] = false;
        info.parents[i].clear();
    }
}

static void print(Info &info) {
    for (size_t i = 0; i < info.size; ++i) {
        cout << i << ": ";
        for (const auto &j : info.parents[i])
            cout << j << ", ";
        cout << endl;
    }
}

static inline void test(Info &info) {
    for (size_t i = 0; i < info.size - 1; ++i) {
        info.distances[i] = 0;
        info.start = i;
        dijkstra(info);
        // print(info);

        create_routes(info);
        print_routes(info);
        clean_info(info);
    }
}

static inline void read_data(Info &info, std::ifstream &file) {
    std::string temp;
    size_t i1 = 0, i2 = 0, current = 0;
    vector<std::string>::iterator it;

    while (!file.eof()) {
        std::getline(file, temp, '-');

        if (temp != "") {
            if ((it = std::find(info.names.begin(), info.names.end(), temp)) == info.names.end()) {
                i1 = current;
                info.names[current++] = std::move(temp);
            }
            else
                i1 = it - info.names.begin();
        }

        std::getline(file, temp, ',');

        if (temp != "") {
            if ((it = std::find(info.names.begin(), info.names.end(), temp)) == info.names.end()) {
                i2 = current;
                info.names[current++] = std::move(temp);
            }
            else
                i2 = it - info.names.begin();
        }

        std::getline(file, temp);
        if (temp != "" && i1 != i2) {
            info.graph[i1].emplace_back(std::make_pair(i2, std::stoi(temp)));
            info.graph[i2].emplace_back(std::make_pair(i1, std::stoi(temp)));
        }
    }
}

void log_print(Info &info) {
    cout << "Size: " << info.size << endl;

    for (size_t i = 0; i < info.size; ++i)
        cout << "Distance[" << i << "]: " << info.distances[i] << endl;
    for (size_t i = 0; i < info.size; ++i)
        cout << "Visited[" << i << "]: " << info.visited[i] << endl;
    for (size_t i = 0; i < info.size; ++i)
        cout << "Name[" << i << "]: " << info.names[i] << endl;
    for (size_t i = 0; i < info.size; ++i)
        for (const auto &j : info.graph[i])
            cout << "From[" << i << "] to[" << j.first << "]: " << j.second << endl;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (file) {
            std::string num;
            std::getline(file, num);
            Info info(std::stoi(num));
            read_data(info, file);
            file.close();
            // log_print(info);
            test(info);
        }
    }
    else
        cout << "usage: ./pathfinder [filename]" << endl;
}
