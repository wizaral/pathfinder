#include <iostream>
#include <vector>

const int INF = 2147483647;

using std::vector, std::pair;

void dijkstra(vector<vector<pair<int, int>>> &graph, int start = 0) {
    vector<int> distances(graph.size(), INF);
    vector<int> parents(graph.size(), -1);
    vector<char> visited(graph.size(), false);
    distances[start] = 0;

    for (int i = 0, v = -1, _size = graph.size(); i < _size; ++i, v = -1) {
        for (int j = 0; j < _size; ++j)
            if (visited[j] == false && (v == -1 || distances[j] < distances[v]))
                v = j;

        if (distances[v] == INF)
            break;

        visited[v] = true;

        for (size_t j = 0, size = graph[v].size(); j < size; ++j) {
            int to = graph[v][j].first, len = graph[v][j].second;

            if (distances[v] + len < distances[to]) {
                distances[to] = distances[v] + len;
                parents[to] = v;
            }
        }
    }

    std::cout << std::string(40, '=') << std::endl;

    for (int i = start + 1, end = distances.size(); i < end; ++i)
        std::cout << i << " : " << distances[i] << std::endl;

    // for (int i = 0, end = parents.size(); i < end; ++i)
    //     std::cout << i << " : " << parents[i] << std::endl;

    std::cout << std::string(40, '=') << std::endl;
}

int main() {
    int size = 5;
    vector<vector<pair<int, int>>> graph(size, vector<pair<int, int>>());   // список вершин: спискок ребер: вершина | вес ребра

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

    graph[0].push_back({1, 11});
    graph[0].push_back({2, 10});

    graph[1].push_back({0, 11});
    graph[1].push_back({3,  5});

    graph[2].push_back({0, 10});
    graph[2].push_back({3,  6});
    graph[2].push_back({4, 15});

    graph[3].push_back({1,  5});
    graph[3].push_back({2,  6});
    graph[3].push_back({4,  4});

    graph[4].push_back({2, 15});
    graph[4].push_back({3,  4});

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

    for (int i = 0; i < size - 1; ++i)
        dijkstra(graph, i);
}
