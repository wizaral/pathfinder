#include "pathfinder.h"

void test(t_info *info) {
    // info->names[0] = mx_strdup("Greenland");
    // info->names[1] = mx_strdup("Bananal");
    // info->names[2] = mx_strdup("Fraser");
    // info->names[3] = mx_strdup("Java");

    // t_pair pair = {1, 8};
    // mx_push_backward(&info->graph[0], &pair);
    // pair.island = 2;
    // pair.distance = 10;
    // mx_push_backward(&info->graph[0], &pair);

    // pair.island = 0;
    // pair.distance = 8;
    // mx_push_backward(&info->graph[1], &pair);
    // pair.island = 2;
    // pair.distance = 3;
    // mx_push_backward(&info->graph[1], &pair);

    // pair.island = 0;
    // pair.distance = 10;
    // mx_push_backward(&info->graph[2], &pair);
    // pair.island = 1;
    // pair.distance = 3;
    // mx_push_backward(&info->graph[2], &pair);
    // pair.island = 3;
    // pair.distance = 5;
    // mx_push_backward(&info->graph[2], &pair);

    // pair.island = 2;
    // pair.distance = 5;
    // mx_push_backward(&info->graph[3], &pair);

    //=======================================================================//

    char str[] = "A";
    for (int i = 0; i < 17; ++i, *str = i + 65)
        info->names[i] = mx_strdup(str);

    t_pair pair = {1, 2};
    mx_push_backward(&info->graph[0], &pair);
    pair.island = 2;
    mx_push_backward(&info->graph[0], &pair);
    pair.island = 3;
    mx_push_backward(&info->graph[0], &pair);

    pair.island = 0;
    mx_push_backward(&info->graph[1], &pair);
    pair.island = 2;
    mx_push_backward(&info->graph[1], &pair);
    pair.island = 6;
    mx_push_backward(&info->graph[1], &pair);
    pair.island = 7;
    mx_push_backward(&info->graph[1], &pair);
    pair.distance = 1;
    pair.island = 4;
    mx_push_backward(&info->graph[1], &pair);

    pair.distance = 2;
    pair.island = 0;
    mx_push_backward(&info->graph[2], &pair);
    pair.island = 1;
    mx_push_backward(&info->graph[2], &pair);
    pair.island = 3;
    mx_push_backward(&info->graph[2], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[2], &pair);
    pair.distance = 1;
    pair.island = 4;
    mx_push_backward(&info->graph[2], &pair);
    pair.island = 5;
    mx_push_backward(&info->graph[2], &pair);

    pair.distance = 2;
    pair.island = 0;
    mx_push_backward(&info->graph[3], &pair);
    pair.island = 2;
    mx_push_backward(&info->graph[3], &pair);
    pair.island = 9;
    mx_push_backward(&info->graph[3], &pair);
    pair.island = 10;
    mx_push_backward(&info->graph[3], &pair);
    pair.distance = 1;
    pair.island = 5;
    mx_push_backward(&info->graph[3], &pair);

    pair.island = 1;
    mx_push_backward(&info->graph[4], &pair);
    pair.island = 2;
    mx_push_backward(&info->graph[4], &pair);
    pair.island = 7;
    mx_push_backward(&info->graph[4], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[4], &pair);

    pair.island = 2;
    mx_push_backward(&info->graph[5], &pair);
    pair.island = 3;
    mx_push_backward(&info->graph[5], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[5], &pair);
    pair.island = 9;
    mx_push_backward(&info->graph[5], &pair);

    pair.distance = 2;
    pair.island = 1;
    mx_push_backward(&info->graph[6], &pair);
    pair.island = 7;
    mx_push_backward(&info->graph[6], &pair);
    pair.island = 13;
    mx_push_backward(&info->graph[6], &pair);

    pair.island = 1;
    mx_push_backward(&info->graph[7], &pair);
    pair.island = 6;
    mx_push_backward(&info->graph[7], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[7], &pair);
    pair.island = 13;
    mx_push_backward(&info->graph[7], &pair);
    pair.distance = 1;
    pair.island = 4;
    mx_push_backward(&info->graph[7], &pair);
    pair.island = 11;
    mx_push_backward(&info->graph[7], &pair);

    pair.distance = 2;
    pair.island = 2;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 7;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 9;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[8], &pair);
    pair.distance = 1;
    pair.island = 4;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 5;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 11;
    mx_push_backward(&info->graph[8], &pair);
    pair.island = 12;
    mx_push_backward(&info->graph[8], &pair);

    pair.distance = 2;
    pair.island = 3;
    mx_push_backward(&info->graph[9], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[9], &pair);
    pair.island = 10;
    mx_push_backward(&info->graph[9], &pair);
    pair.island = 15;
    mx_push_backward(&info->graph[9], &pair);
    pair.distance = 1;
    pair.island = 5;
    mx_push_backward(&info->graph[9], &pair);
    pair.island = 12;
    mx_push_backward(&info->graph[9], &pair);

    pair.distance = 2;
    pair.island = 3;
    mx_push_backward(&info->graph[10], &pair);
    pair.island = 9;
    mx_push_backward(&info->graph[10], &pair);
    pair.island = 15;
    mx_push_backward(&info->graph[10], &pair);

    pair.distance = 1;
    pair.island = 7;
    mx_push_backward(&info->graph[11], &pair);
    pair.island = 8;
    mx_push_backward(&info->graph[11], &pair);
    pair.island = 13;
    mx_push_backward(&info->graph[11], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[11], &pair);

    pair.island = 8;
    mx_push_backward(&info->graph[12], &pair);
    pair.island = 9;
    mx_push_backward(&info->graph[12], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[12], &pair);
    pair.island = 15;
    mx_push_backward(&info->graph[12], &pair);

    pair.distance = 2;
    pair.island = 6;
    mx_push_backward(&info->graph[13], &pair);
    pair.island = 7;
    mx_push_backward(&info->graph[13], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[13], &pair);
    pair.island = 16;
    mx_push_backward(&info->graph[13], &pair);
    pair.distance = 1;
    pair.island = 11;
    mx_push_backward(&info->graph[13], &pair);

    pair.distance = 2;
    pair.island = 8;
    mx_push_backward(&info->graph[14], &pair);
    pair.island = 13;
    mx_push_backward(&info->graph[14], &pair);
    pair.island = 15;
    mx_push_backward(&info->graph[14], &pair);
    pair.island = 16;
    mx_push_backward(&info->graph[14], &pair);
    pair.distance = 1;
    pair.island = 11;
    mx_push_backward(&info->graph[14], &pair);
    pair.island = 12;
    mx_push_backward(&info->graph[14], &pair);

    // pair.distance = 1;
    // pair.island = 12;
    mx_push_backward(&info->graph[15], &pair);
    pair.distance = 2;
    pair.island = 9;
    mx_push_backward(&info->graph[15], &pair);
    pair.island = 10;
    mx_push_backward(&info->graph[15], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[15], &pair);
    pair.island = 16;
    mx_push_backward(&info->graph[15], &pair);

    pair.island = 13;
    mx_push_backward(&info->graph[16], &pair);
    pair.island = 14;
    mx_push_backward(&info->graph[16], &pair);
    pair.island = 15;
    mx_push_backward(&info->graph[16], &pair);
}

int main(int ac, char **av) {
    t_info info;

    if (ac && av) {
        mx_init_info(&info, mx_check_file(av[1]));
        test(&info);    // mx_parse_file(av[1], &info);
        mx_algorithm(&info);
        mx_delete_info(&info);
    }
    else
        mx_throw_usage_error();
    // system("leaks -q pathfinder");
}
