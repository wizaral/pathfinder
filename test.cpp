#include <algorithm>
#include <iostream>
#include <vector>

#define INF 2147483647
using std::string, std::vector, std::pair, std::cout, std::endl;

void print_way(vector<vector<int>> &parents, vector<int> &way, int start) {
    for (int i = 0; i < parents[way.back()].size(); ++i) {
        way.push_back(parents[way.back()][i]);

        if (start != way.back())
            print_way(parents, way, start);
        else {
            cout << "Route: ";
            for (const auto &i : way)
                cout << i << ", ";
            cout << endl;
        }
        way.pop_back();
    }
}

void dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> distances(graph.size(), INF);
    distances[start] = 0;

    vector<vector<int>> parents(graph.size());
    vector<char> visited(graph.size(), false);

    for (size_t i = 0, v = INF, _size = graph.size(); i < _size; ++i, v = INF) {
        for (size_t j = 0; j < _size; ++j)
            if (visited[j] == false && (v == INF || distances[j] < distances[v]))
                v = j;

        visited[v] = true;

        for (size_t j = 0, size = graph[v].size(); j < size; ++j) {
            int to = graph[v][j].first, len = graph[v][j].second;

            if (distances[v] + len <= distances[to]) {
                if (distances[v] + len < distances[to]) {
                    parents[to].erase(parents[to].begin(), parents[to].end());
                    distances[to] = distances[v] + len;
                }
                parents[to].push_back(v);
            }
        }
    }

    cout << string(40, '=') << endl;

    int begin = start + 1;

    for (size_t i = begin, end = distances.size(); i < end; ++i)
        cout << i << " : " << distances[i] << endl;

    cout << string(40, '-') << endl;

    for (size_t i = 0, end = parents.size(); i < end; ++i) {
        std::sort(parents[i].begin(), parents[i].end());

        cout << "P: " << i << " : ";
        for (const auto &j : parents[i])
            cout << j << ", ";
        cout << endl;
    }

    cout << string(40, '-') << endl;

    vector<int> way;

    for (int i = 1, end = parents.size(); i < end; ++i) {
        way.push_back(i);
        print_way(parents, way, start);
        way.pop_back();
    }

    cout << string(40, '=') << endl;
}

int main() {
    size_t size = 7;

    // список вершин: спискок ребер: вершина | вес ребра
    vector<vector<pair<int, int>>> graph(size, vector<pair<int, int>>());

    // ======================================== //

    // Greenland-Bananal,8
    // Fraser-Greenland,10
    // Bananal-Fraser,3
    // Java-Fraser,5

    // Greenland 0
    // Bananal 1
    // Fraser 2
    // Java 3

    // graph[0].push_back({1,  8});
    // graph[0].push_back({2, 10});

    // graph[1].push_back({0,  8});
    // graph[1].push_back({2,  3});

    // graph[2].push_back({0, 10});
    // graph[2].push_back({1,  3});
    // graph[2].push_back({3,  5});

    // graph[3].push_back({2,  5});

    // ======================================== //

    // A-B,11
    // A-C,10
    // B-D,5
    // C-D,6
    // C-E,15
    // D-E,4

    // A 0
    // B 1
    // C 2
    // D 3
    // E 4

    // graph[0].push_back({1, 11});
    // graph[0].push_back({2, 10});

    // graph[1].push_back({0, 11});
    // graph[1].push_back({3,  5});

    // graph[2].push_back({0, 10});
    // graph[2].push_back({3,  6});
    // graph[2].push_back({4, 15});

    // graph[3].push_back({1,  5});
    // graph[3].push_back({2,  6});
    // graph[3].push_back({4,  4});

    // graph[4].push_back({2, 15});
    // graph[4].push_back({3,  4});

    // ======================================== //

    // graph[0].push_back({1,  7});
    // graph[0].push_back({2,  9});
    // graph[0].push_back({5, 14});

    // graph[1].push_back({0,  7});
    // graph[1].push_back({2, 10});
    // graph[1].push_back({3, 15});

    // graph[2].push_back({0,  9});
    // graph[2].push_back({1, 10});
    // graph[2].push_back({3, 11});
    // graph[2].push_back({5,  2});

    // graph[3].push_back({1, 15});
    // graph[3].push_back({2, 11});
    // graph[3].push_back({4,  6});

    // graph[4].push_back({3,  6});
    // graph[4].push_back({5,  9});

    // graph[5].push_back({0, 14});
    // graph[5].push_back({2,  2});
    // graph[5].push_back({4,  9});

    // ======================================== //

    // graph[0].push_back({ 1, 1});
    // graph[0].push_back({ 2, 1});
    // graph[0].push_back({ 3, 1});

    // graph[1].push_back({ 0, 1});
    // graph[1].push_back({ 2, 1});
    // graph[1].push_back({ 4, 1});
    // graph[1].push_back({ 5, 1});
    // graph[1].push_back({ 6, 1});

    // graph[2].push_back({ 0, 1});
    // graph[2].push_back({ 1, 1});
    // graph[2].push_back({ 3, 1});
    // graph[2].push_back({ 5, 1});
    // graph[2].push_back({ 6, 1});
    // graph[2].push_back({ 7, 1});

    // graph[3].push_back({ 0, 1});
    // graph[3].push_back({ 2, 1});
    // graph[3].push_back({ 6, 1});
    // graph[3].push_back({ 7, 1});
    // graph[3].push_back({ 8, 1});

    // graph[4].push_back({ 1, 1});
    // graph[4].push_back({ 5, 1});
    // graph[4].push_back({ 9, 1});

    // graph[5].push_back({ 1, 1});
    // graph[5].push_back({ 2, 1});
    // graph[5].push_back({ 4, 1});
    // graph[5].push_back({ 6, 1});
    // graph[5].push_back({ 9, 1});
    // graph[5].push_back({10, 1});

    // graph[6].push_back({ 1, 1});
    // graph[6].push_back({ 2, 1});
    // graph[6].push_back({ 3, 1});
    // graph[6].push_back({ 5, 1});
    // graph[6].push_back({ 7, 1});
    // graph[6].push_back({ 9, 1});
    // graph[6].push_back({10, 1});
    // graph[6].push_back({11, 1});

    // graph[7].push_back({ 2, 1});
    // graph[7].push_back({ 3, 1});
    // graph[7].push_back({ 6, 1});
    // graph[7].push_back({ 8, 1});
    // graph[7].push_back({10, 1});
    // graph[7].push_back({11, 1});

    // graph[8].push_back({ 3, 1});
    // graph[8].push_back({ 7, 1});
    // graph[8].push_back({11, 1});

    // graph[9].push_back({ 4, 1});
    // graph[9].push_back({ 5, 1});
    // graph[9].push_back({ 6, 1});
    // graph[9].push_back({10, 1});
    // graph[9].push_back({12, 1});

    // graph[10].push_back({ 5, 1});
    // graph[10].push_back({ 6, 1});
    // graph[10].push_back({ 7, 1});
    // graph[10].push_back({ 9, 1});
    // graph[10].push_back({11, 1});
    // graph[10].push_back({12, 1});

    // graph[11].push_back({ 6, 1});
    // graph[11].push_back({ 7, 1});
    // graph[11].push_back({ 8, 1});
    // graph[11].push_back({10, 1});
    // graph[11].push_back({12, 1});

    // graph[12].push_back({ 9, 1});
    // graph[12].push_back({10, 1});
    // graph[12].push_back({11, 1});

    // ======================================== //

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

    // 0 Home
    // 1 BusStop
    // 2 Work
    // 3 Taxi
    // 4 Metro
    // 5 Gym
    // 6 Park

    graph[0].push_back({1, 4});
    graph[0].push_back({3, 1});
    graph[0].push_back({4, 6});

    graph[1].push_back({0, 4});
    graph[1].push_back({2, 7});
    graph[1].push_back({6, 18});

    graph[2].push_back({1, 7});
    graph[2].push_back({3, 10});
    graph[2].push_back({4, 8});
    graph[2].push_back({5, 2});

    graph[3].push_back({0, 1});
    graph[3].push_back({2, 10});
    graph[3].push_back({5, 12});

    graph[4].push_back({0, 6});
    graph[4].push_back({2, 8});
    graph[4].push_back({6, 16});

    graph[5].push_back({2, 2});
    graph[5].push_back({3, 12});

    graph[6].push_back({1, 18});
    graph[6].push_back({5, 16});


    for (int i = 0; i < size - 1; ++i)
        dijkstra(graph, i);
    // dijkstra(graph, 0);
}
