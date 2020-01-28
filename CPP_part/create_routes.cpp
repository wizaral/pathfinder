#include "pathfinder.h"

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

void create_routes(Info &info) {
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
