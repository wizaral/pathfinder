#include "pathfinder.h"

int main(int ac, char **av) {
    t_info info;

    if (ac == 2) {
        mx_init_info(&info, mx_check_file(av[1]));
        mx_parse_file(&info, av[1]);
        mx_algorithm(&info);
        // mx_delete_info(&info);
    }
    else
        mx_throw_usage_error();
    // system("leaks -q pathfinder");
}
