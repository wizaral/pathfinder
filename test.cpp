#include <iostream>
#include <vector>

const int INF = 21;

using std::vector, std::pair;

int main() {
    int n;
    int s = 0; // start point

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    vector<int> d(n, INF);
    vector<int> p(n);
    d[s] = 0;

    vector<char> u(n, false);

    for (int i = 0, v = -1; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (u[j] == false && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == INF)
            break;

        u[v] = true;

        for (size_t j = 0, size = g[v].size(); j < size; ++j) {
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
