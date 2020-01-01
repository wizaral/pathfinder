#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#define INF 2147483647
using t_ull = unsigned long long;
using std::ostream, std::vector, std::pair, std::cout, std::endl;

struct Info {
    Info(t_ull size)
        : graph(vector<vector<pair<t_ull, t_ull>>>(size, vector<pair<t_ull, t_ull>>())),
        parents(vector<vector<t_ull>>(size)),
        routes(vector<vector<t_ull>>()),
        distances(vector<t_ull>(size, INF)),
        visited(vector<char>(size, false)),
        names(vector<std::string>(size)),
        size(size) {}

    vector<vector<pair<t_ull, t_ull>>> graph;
    vector<vector<t_ull>> parents;
    vector<vector<t_ull>> routes;
    vector<t_ull> distances;
    vector<char> visited;
    vector<std::string> names;
    t_ull size;
};

void test1(Info &info) {
    info.graph[0].push_back({1,  8});
    info.graph[0].push_back({2, 10});

    info.graph[1].push_back({0,  8});
    info.graph[1].push_back({2,  3});

    info.graph[2].push_back({0, 10});
    info.graph[2].push_back({1,  3});
    info.graph[2].push_back({3,  5});

    info.graph[3].push_back({2,  5});

    info.names[0] = "Greenland";
    info.names[1] = "Bananal";
    info.names[2] = "Fraser";
    info.names[3] = "Java";
}

void test2(Info &info) {
    info.graph[0].push_back({1, 11});
    info.graph[0].push_back({2, 10});

    info.graph[1].push_back({0, 11});
    info.graph[1].push_back({3,  5});

    info.graph[2].push_back({0, 10});
    info.graph[2].push_back({3,  6});
    info.graph[2].push_back({4, 15});

    info.graph[3].push_back({1,  5});
    info.graph[3].push_back({2,  6});
    info.graph[3].push_back({4,  4});

    info.graph[4].push_back({2, 15});
    info.graph[4].push_back({3,  4});

    for (int i = 0; i < 5; ++i)
        info.names[i] = std::string(1, i + 65);
}

void test3(Info &info) {
    info.graph[0].push_back({1, 1});
    info.graph[0].push_back({2, 1});

    info.graph[1].push_back({0, 1});
    info.graph[1].push_back({2, 1});

    info.graph[2].push_back({0, 1});
    info.graph[2].push_back({1, 1});

    info.names[0] = "Blade";
    info.names[1] = "Wizard";
    info.names[2] = "Drive";
}

// void test3(Info &info) {
//     info.graph[0].push_back({1, 1});
//     info.graph[0].push_back({2, 2});

//     info.graph[1].push_back({0, 1});
//     info.graph[1].push_back({2, 3});

//     info.graph[2].push_back({0, 2});
//     info.graph[2].push_back({1, 3});

//     info.names[0] = "Blade";
//     info.names[1] = "Wizard";
//     info.names[2] = "Drive";
// }

void test4(Info &info) {
    info.graph[0].push_back({1, 1});

    info.graph[1].push_back({0, 1});
    info.graph[1].push_back({2, 2});

    info.graph[2].push_back({1, 2});
    info.graph[2].push_back({3, 8});

    info.graph[3].push_back({2, 8});

    info.names[0] = "One";
    info.names[1] = "Two";
    info.names[2] = "Zero";
    info.names[3] = "Eight";
}

void test5(Info &info) {
    info.graph[0].push_back({1, 471});
    info.graph[0].push_back({3, 766});
    info.graph[0].push_back({4, 2403});
    info.graph[0].push_back({5, 1141});
    info.graph[0].push_back({6, 11864});
    info.graph[0].push_back({7, 11079});

    info.graph[1].push_back({0, 471});
    info.graph[1].push_back({2, 340});

    info.graph[2].push_back({1, 340});
    info.graph[3].push_back({0, 766});
    info.graph[4].push_back({0, 2403});
    info.graph[5].push_back({0, 1141});
    info.graph[6].push_back({0, 11864});
    info.graph[7].push_back({0, 11079});

    info.names[0] = "Kyiv";
    info.names[1] = "Kharkiv";
    info.names[2] = "Nikopol";
    info.names[3] = "Warsaw";
    info.names[4] = "Paris";
    info.names[5] = "Prague";
    info.names[6] = "Singapore";
    info.names[7] = "Tokyo";
}

void test6(Info &info) {
    info.graph[0].push_back({1, 4});
    info.graph[0].push_back({3, 1});
    info.graph[0].push_back({4, 6});

    info.graph[1].push_back({0, 4});
    info.graph[1].push_back({2, 7});
    info.graph[1].push_back({6, 18});

    info.graph[2].push_back({1, 7});
    info.graph[2].push_back({3, 10});
    info.graph[2].push_back({4, 8});
    info.graph[2].push_back({5, 2});

    info.graph[3].push_back({0, 1});
    info.graph[3].push_back({2, 10});
    info.graph[3].push_back({5, 12});

    info.graph[4].push_back({0, 6});
    info.graph[4].push_back({2, 8});
    info.graph[4].push_back({6, 16});

    info.graph[5].push_back({2, 2});
    info.graph[5].push_back({3, 12});

    info.graph[6].push_back({1, 18});
    info.graph[6].push_back({5, 16});

    info.names[0] = "Home";
    info.names[1] = "BusStop";
    info.names[2] = "Work";
    info.names[3] = "Taxi";
    info.names[4] = "Metro";
    info.names[5] = "Gym";
    info.names[6] = "Park";
}

void test7(Info &info) {
    info.graph[0].push_back({ 1, 1});
    info.graph[0].push_back({ 2, 1});
    info.graph[0].push_back({ 3, 1});

    info.graph[1].push_back({ 0, 1});
    info.graph[1].push_back({ 2, 1});
    info.graph[1].push_back({ 4, 1});
    info.graph[1].push_back({ 5, 1});
    info.graph[1].push_back({ 6, 1});

    info.graph[2].push_back({ 0, 1});
    info.graph[2].push_back({ 1, 1});
    info.graph[2].push_back({ 3, 1});
    info.graph[2].push_back({ 5, 1});
    info.graph[2].push_back({ 6, 1});
    info.graph[2].push_back({ 7, 1});

    info.graph[3].push_back({ 0, 1});
    info.graph[3].push_back({ 2, 1});
    info.graph[3].push_back({ 6, 1});
    info.graph[3].push_back({ 7, 1});
    info.graph[3].push_back({ 8, 1});

    info.graph[4].push_back({ 1, 1});
    info.graph[4].push_back({ 5, 1});
    info.graph[4].push_back({ 9, 1});

    info.graph[5].push_back({ 1, 1});
    info.graph[5].push_back({ 2, 1});
    info.graph[5].push_back({ 4, 1});
    info.graph[5].push_back({ 6, 1});
    info.graph[5].push_back({ 9, 1});
    info.graph[5].push_back({10, 1});

    info.graph[6].push_back({ 1, 1});
    info.graph[6].push_back({ 2, 1});
    info.graph[6].push_back({ 3, 1});
    info.graph[6].push_back({ 5, 1});
    info.graph[6].push_back({ 7, 1});
    info.graph[6].push_back({ 9, 1});
    info.graph[6].push_back({10, 1});
    info.graph[6].push_back({11, 1});

    info.graph[7].push_back({ 2, 1});
    info.graph[7].push_back({ 3, 1});
    info.graph[7].push_back({ 6, 1});
    info.graph[7].push_back({ 8, 1});
    info.graph[7].push_back({10, 1});
    info.graph[7].push_back({11, 1});

    info.graph[8].push_back({ 3, 1});
    info.graph[8].push_back({ 7, 1});
    info.graph[8].push_back({11, 1});

    info.graph[9].push_back({ 4, 1});
    info.graph[9].push_back({ 5, 1});
    info.graph[9].push_back({ 6, 1});
    info.graph[9].push_back({10, 1});
    info.graph[9].push_back({12, 1});

    info.graph[10].push_back({ 5, 1});
    info.graph[10].push_back({ 6, 1});
    info.graph[10].push_back({ 7, 1});
    info.graph[10].push_back({ 9, 1});
    info.graph[10].push_back({11, 1});
    info.graph[10].push_back({12, 1});

    info.graph[11].push_back({ 6, 1});
    info.graph[11].push_back({ 7, 1});
    info.graph[11].push_back({ 8, 1});
    info.graph[11].push_back({10, 1});
    info.graph[11].push_back({12, 1});

    info.graph[12].push_back({ 9, 1});
    info.graph[12].push_back({10, 1});
    info.graph[12].push_back({11, 1});

    for (int i = 0; i < 13; ++i)
        info.names[i] = std::string(1, i + 65);
}

void test8(Info &info) {
    info.graph[0].push_back({ 1, 2});
    info.graph[0].push_back({ 2, 2});
    info.graph[0].push_back({ 3, 2});

    info.graph[1].push_back({ 0, 2});
    info.graph[1].push_back({ 2, 2});
    info.graph[1].push_back({ 4, 1});
    info.graph[1].push_back({ 6, 2});
    info.graph[1].push_back({ 7, 2});

    info.graph[2].push_back({ 0, 2});
    info.graph[2].push_back({ 1, 2});
    info.graph[2].push_back({ 3, 2});
    info.graph[2].push_back({ 4, 1});
    info.graph[2].push_back({ 5, 1});
    info.graph[2].push_back({ 8, 2});

    info.graph[3].push_back({ 0, 2});
    info.graph[3].push_back({ 2, 2});
    info.graph[3].push_back({ 5, 1});
    info.graph[3].push_back({ 9, 2});
    info.graph[3].push_back({10, 2});

    info.graph[4].push_back({ 1, 1});
    info.graph[4].push_back({ 2, 1});
    info.graph[4].push_back({ 7, 1});
    info.graph[4].push_back({ 8, 1});

    info.graph[5].push_back({ 2, 1});
    info.graph[5].push_back({ 3, 1});
    info.graph[5].push_back({ 8, 1});
    info.graph[5].push_back({ 9, 1});

    info.graph[6].push_back({ 1, 2});
    info.graph[6].push_back({ 7, 2});
    info.graph[6].push_back({13, 2});

    info.graph[7].push_back({ 1, 2});
    info.graph[7].push_back({ 4, 1});
    info.graph[7].push_back({ 6, 2});
    info.graph[7].push_back({ 8, 2});
    info.graph[7].push_back({11, 1});
    info.graph[7].push_back({13, 2});

    info.graph[8].push_back({ 2, 2});
    info.graph[8].push_back({ 4, 1});
    info.graph[8].push_back({ 5, 1});
    info.graph[8].push_back({ 7, 2});
    info.graph[8].push_back({ 9, 2});
    info.graph[8].push_back({11, 1});
    info.graph[8].push_back({12, 1});
    info.graph[8].push_back({14, 2});

    info.graph[9].push_back({ 3, 2});
    info.graph[9].push_back({ 5, 1});
    info.graph[9].push_back({ 8, 2});
    info.graph[9].push_back({10, 2});
    info.graph[9].push_back({12, 1});
    info.graph[9].push_back({15, 2});

    info.graph[10].push_back({ 3, 2});
    info.graph[10].push_back({ 9, 2});
    info.graph[10].push_back({15, 2});

    info.graph[11].push_back({ 7, 1});
    info.graph[11].push_back({ 8, 1});
    info.graph[11].push_back({13, 1});
    info.graph[11].push_back({14, 1});

    info.graph[12].push_back({ 8, 1});
    info.graph[12].push_back({ 9, 1});
    info.graph[12].push_back({14, 1});
    info.graph[12].push_back({15, 1});

    info.graph[13].push_back({ 6, 2});
    info.graph[13].push_back({ 7, 2});
    info.graph[13].push_back({11, 1});
    info.graph[13].push_back({14, 2});
    info.graph[13].push_back({16, 2});

    info.graph[14].push_back({ 8, 2});
    info.graph[14].push_back({11, 1});
    info.graph[14].push_back({12, 1});
    info.graph[14].push_back({13, 2});
    info.graph[14].push_back({15, 2});
    info.graph[14].push_back({16, 2});

    info.graph[15].push_back({ 9, 2});
    info.graph[15].push_back({10, 2});
    info.graph[15].push_back({12, 1});
    info.graph[15].push_back({14, 2});
    info.graph[15].push_back({16, 2});

    info.graph[16].push_back({13, 2});
    info.graph[16].push_back({14, 2});
    info.graph[16].push_back({15, 2});

    for (int i = 0; i < 17; ++i)
        info.names[i] = std::string(1, i + 65);
}

void test9(Info &info) {
    info.graph[0].push_back({1, 1306});
    info.graph[0].push_back({4, 2161});
    info.graph[0].push_back({5, 2661});

    info.graph[1].push_back({0, 1306});
    info.graph[1].push_back({2, 919});
    info.graph[1].push_back({3, 629});

    info.graph[2].push_back({1, 919});
    info.graph[2].push_back({3, 435});
    info.graph[2].push_back({4, 1225});
    info.graph[2].push_back({6, 1983});

    info.graph[3].push_back({1, 629});
    info.graph[3].push_back({2, 435});

    info.graph[4].push_back({0, 2161});
    info.graph[4].push_back({2, 1225});
    info.graph[4].push_back({5, 1483});
    info.graph[4].push_back({6, 1258});

    info.graph[5].push_back({0, 2661});
    info.graph[5].push_back({4, 1483});
    info.graph[5].push_back({6, 1532});
    info.graph[5].push_back({7, 661});

    info.graph[6].push_back({2, 1983});
    info.graph[6].push_back({4, 1258});
    info.graph[6].push_back({5, 1532});
    info.graph[6].push_back({8, 2113});
    info.graph[6].push_back({11, 2161});

    info.graph[7].push_back({5, 661});
    info.graph[7].push_back({8, 1145});
    info.graph[7].push_back({9, 1613});

    info.graph[8].push_back({6, 2113});
    info.graph[8].push_back({7, 1145});
    info.graph[8].push_back({9, 725});
    info.graph[8].push_back({10, 383});
    info.graph[8].push_back({11, 1709});

    info.graph[9].push_back({7, 1613});
    info.graph[9].push_back({8, 725});
    info.graph[9].push_back({10, 338});

    info.graph[10].push_back({8, 383});
    info.graph[10].push_back({9, 338});
    info.graph[10].push_back({11, 2145});

    info.graph[11].push_back({6, 2161});
    info.graph[11].push_back({8, 1709});
    info.graph[11].push_back({10, 2145});

    info.names[0] = "Seattle";
    info.names[1] = "SanFrancisco";
    info.names[2] = "LasVegas";
    info.names[3] = "LosAngeles";
    info.names[4] = "Denver";
    info.names[5] = "Minneapolis";
    info.names[6] = "Dallas";
    info.names[7] = "Chicago";
    info.names[8] = "WashDC";
    info.names[9] = "Boston";
    info.names[10] = "NewYork";
    info.names[11] = "Miami";
}
