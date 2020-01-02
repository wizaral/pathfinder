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
        size(size) {}

    vector<vector<pair<ull, ull>>> graph;
    vector<vector<ull>> parents;
    vector<vector<ull>> routes;
    vector<ull> distances;
    vector<char> visited;
    vector<std::string> names;
    ull size;
};

// 4
// Greenland-Bananal,8
// Fraser-Greenland,10
// Bananal-Fraser,3
// Java-Fraser,5

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

// 5
// A-B,11
// A-C,10
// B-D,5
// C-D,6
// C-E,15
// D-E,4

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

// 3
// Blade-Wizard,1
// Drive-Blade,1
// Wizard-Drive,1

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

// 3
// Blade-Wizard,1
// Drive-Blade,2
// Wizard-Drive,3

void test4(Info &info) {
    info.graph[0].push_back({1, 1});
    info.graph[0].push_back({2, 2});

    info.graph[1].push_back({0, 1});
    info.graph[1].push_back({2, 3});

    info.graph[2].push_back({0, 2});
    info.graph[2].push_back({1, 3});

    info.names[0] = "Blade";
    info.names[1] = "Wizard";
    info.names[2] = "Drive";
}

// 4
// One-Two,1
// Zero-Eight,8
// Two-Zero,2

void test5(Info &info) {
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

// 8
// Kyiv-Kharkiv,471
// Nikopol-Kharkiv,340
// Kyiv-Warsaw,766
// Kyiv-Paris,2403
// Kyiv-Prague,1141
// Kyiv-Singapore,11864
// Kyiv-Tokyo,11079

void test6(Info &info) {
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

void test7(Info &info) {
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

void test8(Info &info) {
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

void test9(Info &info) {
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

void test10(Info &info) {
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
