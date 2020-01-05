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
        start(0),
        size(size) {}

    vector<vector<pair<ull, ull>>> graph;
    vector<vector<ull>> parents;
    vector<vector<ull>> routes;
    vector<ull> distances;
    vector<char> visited;
    vector<std::string> names;
    ull start;
    ull size;
};

// 4
// Greenland-Bananal,8
// Fraser-Greenland,10
// Bananal-Fraser,3
// Java-Fraser,5

void test1(Info &info) {
    info.graph[0].push_back({1, 8});
    info.graph[0].push_back({2, 10});

    info.graph[1].push_back({0, 8});
    info.graph[1].push_back({2, 3});

    info.graph[2].push_back({0, 10});
    info.graph[2].push_back({1, 3});
    info.graph[2].push_back({3, 5});

    info.graph[3].push_back({2, 5});

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
    info.graph[1].push_back({3, 5});

    info.graph[2].push_back({0, 10});
    info.graph[2].push_back({3, 6});
    info.graph[2].push_back({4, 15});

    info.graph[3].push_back({1, 5});
    info.graph[3].push_back({2, 6});
    info.graph[3].push_back({4, 4});

    info.graph[4].push_back({2, 15});
    info.graph[4].push_back({3, 4});

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
    info.graph[0].push_back({1, 1});
    info.graph[0].push_back({2, 1});
    info.graph[0].push_back({3, 1});

    info.graph[1].push_back({0, 1});
    info.graph[1].push_back({2, 1});
    info.graph[1].push_back({4, 1});
    info.graph[1].push_back({5, 1});
    info.graph[1].push_back({6, 1});

    info.graph[2].push_back({0, 1});
    info.graph[2].push_back({1, 1});
    info.graph[2].push_back({3, 1});
    info.graph[2].push_back({5, 1});
    info.graph[2].push_back({6, 1});
    info.graph[2].push_back({7, 1});

    info.graph[3].push_back({0, 1});
    info.graph[3].push_back({2, 1});
    info.graph[3].push_back({6, 1});
    info.graph[3].push_back({7, 1});
    info.graph[3].push_back({8, 1});

    info.graph[4].push_back({1, 1});
    info.graph[4].push_back({5, 1});
    info.graph[4].push_back({9, 1});

    info.graph[5].push_back({1, 1});
    info.graph[5].push_back({2, 1});
    info.graph[5].push_back({4, 1});
    info.graph[5].push_back({6, 1});
    info.graph[5].push_back({9, 1});
    info.graph[5].push_back({10, 1});

    info.graph[6].push_back({1, 1});
    info.graph[6].push_back({2, 1});
    info.graph[6].push_back({3, 1});
    info.graph[6].push_back({5, 1});
    info.graph[6].push_back({7, 1});
    info.graph[6].push_back({9, 1});
    info.graph[6].push_back({10, 1});
    info.graph[6].push_back({11, 1});

    info.graph[7].push_back({2, 1});
    info.graph[7].push_back({3, 1});
    info.graph[7].push_back({6, 1});
    info.graph[7].push_back({8, 1});
    info.graph[7].push_back({10, 1});
    info.graph[7].push_back({11, 1});

    info.graph[8].push_back({3, 1});
    info.graph[8].push_back({7, 1});
    info.graph[8].push_back({11, 1});

    info.graph[9].push_back({4, 1});
    info.graph[9].push_back({5, 1});
    info.graph[9].push_back({6, 1});
    info.graph[9].push_back({10, 1});
    info.graph[9].push_back({12, 1});

    info.graph[10].push_back({5, 1});
    info.graph[10].push_back({6, 1});
    info.graph[10].push_back({7, 1});
    info.graph[10].push_back({9, 1});
    info.graph[10].push_back({11, 1});
    info.graph[10].push_back({12, 1});

    info.graph[11].push_back({6, 1});
    info.graph[11].push_back({7, 1});
    info.graph[11].push_back({8, 1});
    info.graph[11].push_back({10, 1});
    info.graph[11].push_back({12, 1});

    info.graph[12].push_back({9, 1});
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
    info.graph[0].push_back({1, 2});
    info.graph[0].push_back({2, 2});
    info.graph[0].push_back({3, 2});

    info.graph[1].push_back({0, 2});
    info.graph[1].push_back({2, 2});
    info.graph[1].push_back({4, 1});
    info.graph[1].push_back({6, 2});
    info.graph[1].push_back({7, 2});

    info.graph[2].push_back({0, 2});
    info.graph[2].push_back({1, 2});
    info.graph[2].push_back({3, 2});
    info.graph[2].push_back({4, 1});
    info.graph[2].push_back({5, 1});
    info.graph[2].push_back({8, 2});

    info.graph[3].push_back({0, 2});
    info.graph[3].push_back({2, 2});
    info.graph[3].push_back({5, 1});
    info.graph[3].push_back({9, 2});
    info.graph[3].push_back({10, 2});

    info.graph[4].push_back({1, 1});
    info.graph[4].push_back({2, 1});
    info.graph[4].push_back({7, 1});
    info.graph[4].push_back({8, 1});

    info.graph[5].push_back({2, 1});
    info.graph[5].push_back({3, 1});
    info.graph[5].push_back({8, 1});
    info.graph[5].push_back({9, 1});

    info.graph[6].push_back({1, 2});
    info.graph[6].push_back({7, 2});
    info.graph[6].push_back({13, 2});

    info.graph[7].push_back({1, 2});
    info.graph[7].push_back({4, 1});
    info.graph[7].push_back({6, 2});
    info.graph[7].push_back({8, 2});
    info.graph[7].push_back({11, 1});
    info.graph[7].push_back({13, 2});

    info.graph[8].push_back({2, 2});
    info.graph[8].push_back({4, 1});
    info.graph[8].push_back({5, 1});
    info.graph[8].push_back({7, 2});
    info.graph[8].push_back({9, 2});
    info.graph[8].push_back({11, 1});
    info.graph[8].push_back({12, 1});
    info.graph[8].push_back({14, 2});

    info.graph[9].push_back({3, 2});
    info.graph[9].push_back({5, 1});
    info.graph[9].push_back({8, 2});
    info.graph[9].push_back({10, 2});
    info.graph[9].push_back({12, 1});
    info.graph[9].push_back({15, 2});

    info.graph[10].push_back({3, 2});
    info.graph[10].push_back({9, 2});
    info.graph[10].push_back({15, 2});

    info.graph[11].push_back({7, 1});
    info.graph[11].push_back({8, 1});
    info.graph[11].push_back({13, 1});
    info.graph[11].push_back({14, 1});

    info.graph[12].push_back({8, 1});
    info.graph[12].push_back({9, 1});
    info.graph[12].push_back({14, 1});
    info.graph[12].push_back({15, 1});

    info.graph[13].push_back({6, 2});
    info.graph[13].push_back({7, 2});
    info.graph[13].push_back({11, 1});
    info.graph[13].push_back({14, 2});
    info.graph[13].push_back({16, 2});

    info.graph[14].push_back({8, 2});
    info.graph[14].push_back({11, 1});
    info.graph[14].push_back({12, 1});
    info.graph[14].push_back({13, 2});
    info.graph[14].push_back({15, 2});
    info.graph[14].push_back({16, 2});

    info.graph[15].push_back({9, 2});
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

// 49
// A-B,1
// A-C,1
// B-D,1
// B-E,1
// C-E,1
// C-F,1
// D-G,1
// D-H,1
// E-H,1
// E-I,1
// F-I,1
// F-J,1
// G-K,1
// G-L,1
// H-L,1
// H-M,1
// I-M,1
// I-N,1
// J-N,1
// J-O,1
// K-P,1
// K-Q,1
// L-Q,1
// L-R,1
// M-R,1
// M-S,1
// N-S,1
// N-T,1
// O-T,1
// O-U,1
// P-V,1
// P-W,1
// Q-W,1
// Q-X,1
// R-X,1
// R-Y,1
// S-Y,1
// S-Z,1
// T-Z,1
// T-AA,1
// U-AA,1
// U-BB,1
// V-CC,1
// W-CC,1
// W-DD,1
// X-DD,1
// X-EE,1
// Y-EE,1
// Y-FF,1
// Z-FF,1
// Z-GG,1
// AA-GG,1
// AA-HH,1
// BB-HH,1
// CC-II,1
// DD-II,1
// DD-JJ,1
// EE-JJ,1
// EE-KK,1
// FF-KK,1
// FF-LL,1
// GG-LL,1
// GG-MM,1
// HH-MM,1
// II-NN,1
// JJ-NN,1
// JJ-OO,1
// KK-OO,1
// KK-PP,1
// LL-PP,1
// LL-QQ,1
// MM-QQ,1
// NN-RR,1
// OO-RR,1
// OO-SS,1
// PP-SS,1
// PP-TT,1
// QQ-TT,1
// RR-UU,1
// SS-UU,1
// SS-VV,1
// TT-VV,1
// UU-WW,1
// VV-WW,1

void test10(Info &info) {
    info.graph[0].push_back({1, 1});
    info.graph[0].push_back({2, 1});

    info.graph[1].push_back({0, 1});
    info.graph[1].push_back({3, 1});
    info.graph[1].push_back({4, 1});

    info.graph[2].push_back({0, 1});
    info.graph[2].push_back({4, 1});
    info.graph[2].push_back({5, 1});

    info.graph[3].push_back({1, 1});
    info.graph[3].push_back({6, 1});
    info.graph[3].push_back({7, 1});

    info.graph[4].push_back({1, 1});
    info.graph[4].push_back({2, 1});
    info.graph[4].push_back({7, 1});
    info.graph[4].push_back({8, 1});

    info.graph[5].push_back({2, 1});
    info.graph[5].push_back({8, 1});
    info.graph[5].push_back({9, 1});

    info.graph[6].push_back({3, 1});
    info.graph[6].push_back({10, 1});
    info.graph[6].push_back({11, 1});

    info.graph[7].push_back({3, 1});
    info.graph[7].push_back({4, 1});
    info.graph[7].push_back({11, 1});
    info.graph[7].push_back({12, 1});

    info.graph[8].push_back({4, 1});
    info.graph[8].push_back({5, 1});
    info.graph[8].push_back({12, 1});
    info.graph[8].push_back({13, 1});

    info.graph[9].push_back({5, 1});
    info.graph[9].push_back({13, 1});
    info.graph[9].push_back({14, 1});

    info.graph[10].push_back({6, 1});
    info.graph[10].push_back({15, 1});
    info.graph[10].push_back({16, 1});

    info.graph[11].push_back({6, 1});
    info.graph[11].push_back({7, 1});
    info.graph[11].push_back({16, 1});
    info.graph[11].push_back({17, 1});

    info.graph[12].push_back({7, 1});
    info.graph[12].push_back({8, 1});
    info.graph[12].push_back({17, 1});
    info.graph[12].push_back({18, 1});

    info.graph[13].push_back({8, 1});
    info.graph[13].push_back({9, 1});
    info.graph[13].push_back({18, 1});
    info.graph[13].push_back({19, 1});

    info.graph[14].push_back({9, 1});
    info.graph[14].push_back({19, 1});
    info.graph[14].push_back({20, 1});

    info.graph[15].push_back({10, 1});
    info.graph[15].push_back({21, 1});
    info.graph[15].push_back({22, 1});

    info.graph[16].push_back({10, 1});
    info.graph[16].push_back({11, 1});
    info.graph[16].push_back({22, 1});
    info.graph[16].push_back({23, 1});

    info.graph[17].push_back({11, 1});
    info.graph[17].push_back({12, 1});
    info.graph[17].push_back({23, 1});
    info.graph[17].push_back({24, 1});

    info.graph[18].push_back({12, 1});
    info.graph[18].push_back({13, 1});
    info.graph[18].push_back({24, 1});
    info.graph[18].push_back({25, 1});

    info.graph[19].push_back({13, 1});
    info.graph[19].push_back({14, 1});
    info.graph[19].push_back({25, 1});
    info.graph[19].push_back({26, 1});

    info.graph[20].push_back({14, 1});
    info.graph[20].push_back({26, 1});
    info.graph[20].push_back({27, 1});

    info.graph[21].push_back({15, 1});
    info.graph[21].push_back({28, 1});

    info.graph[22].push_back({15, 1});
    info.graph[22].push_back({16, 1});
    info.graph[22].push_back({28, 1});
    info.graph[22].push_back({29, 1});

    info.graph[23].push_back({16, 1});
    info.graph[23].push_back({17, 1});
    info.graph[23].push_back({29, 1});
    info.graph[23].push_back({30, 1});

    info.graph[24].push_back({17, 1});
    info.graph[24].push_back({18, 1});
    info.graph[24].push_back({30, 1});
    info.graph[24].push_back({31, 1});

    info.graph[25].push_back({18, 1});
    info.graph[25].push_back({19, 1});
    info.graph[25].push_back({31, 1});
    info.graph[25].push_back({32, 1});

    info.graph[26].push_back({19, 1});
    info.graph[26].push_back({20, 1});
    info.graph[26].push_back({32, 1});
    info.graph[26].push_back({33, 1});

    info.graph[27].push_back({20, 1});
    info.graph[27].push_back({33, 1});

    info.graph[28].push_back({21, 1});
    info.graph[28].push_back({22, 1});
    info.graph[28].push_back({34, 1});

    info.graph[29].push_back({22, 1});
    info.graph[29].push_back({23, 1});
    info.graph[29].push_back({34, 1});
    info.graph[29].push_back({35, 1});

    info.graph[30].push_back({23, 1});
    info.graph[30].push_back({24, 1});
    info.graph[30].push_back({35, 1});
    info.graph[30].push_back({36, 1});

    info.graph[31].push_back({24, 1});
    info.graph[31].push_back({25, 1});
    info.graph[31].push_back({36, 1});
    info.graph[31].push_back({37, 1});

    info.graph[32].push_back({25, 1});
    info.graph[32].push_back({26, 1});
    info.graph[32].push_back({37, 1});
    info.graph[32].push_back({38, 1});

    info.graph[33].push_back({26, 1});
    info.graph[33].push_back({27, 1});
    info.graph[33].push_back({38, 1});

    info.graph[34].push_back({28, 1});
    info.graph[34].push_back({29, 1});
    info.graph[34].push_back({39, 1});

    info.graph[35].push_back({29, 1});
    info.graph[35].push_back({30, 1});
    info.graph[35].push_back({39, 1});
    info.graph[35].push_back({40, 1});

    info.graph[36].push_back({30, 1});
    info.graph[36].push_back({31, 1});
    info.graph[36].push_back({40, 1});
    info.graph[36].push_back({41, 1});

    info.graph[37].push_back({31, 1});
    info.graph[37].push_back({32, 1});
    info.graph[37].push_back({41, 1});
    info.graph[37].push_back({42, 1});

    info.graph[38].push_back({32, 1});
    info.graph[38].push_back({33, 1});
    info.graph[38].push_back({42, 1});

    info.graph[39].push_back({34, 1});
    info.graph[39].push_back({35, 1});
    info.graph[39].push_back({43, 1});

    info.graph[40].push_back({35, 1});
    info.graph[40].push_back({36, 1});
    info.graph[40].push_back({43, 1});
    info.graph[40].push_back({44, 1});

    info.graph[41].push_back({36, 1});
    info.graph[41].push_back({37, 1});
    info.graph[41].push_back({44, 1});
    info.graph[41].push_back({45, 1});

    info.graph[42].push_back({37, 1});
    info.graph[42].push_back({38, 1});
    info.graph[42].push_back({45, 1});

    info.graph[43].push_back({39, 1});
    info.graph[43].push_back({40, 1});
    info.graph[43].push_back({46, 1});

    info.graph[44].push_back({40, 1});
    info.graph[44].push_back({41, 1});
    info.graph[44].push_back({46, 1});
    info.graph[44].push_back({47, 1});

    info.graph[45].push_back({41, 1});
    info.graph[45].push_back({42, 1});
    info.graph[45].push_back({47, 1});

    info.graph[46].push_back({43, 1});
    info.graph[46].push_back({44, 1});
    info.graph[46].push_back({48, 1});

    info.graph[47].push_back({44, 1});
    info.graph[47].push_back({45, 1});
    info.graph[47].push_back({48, 1});

    info.graph[48].push_back({46, 1});
    info.graph[48].push_back({47, 1});

    for (int i = 0; i < 26; ++i)
        info.names[i] = std::string(1, i + 65);
    for (int i = 0; i < 23; ++i)
        info.names[i + 26] = std::string(2, i + 65);
}
