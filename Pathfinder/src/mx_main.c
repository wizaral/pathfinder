#include "pathfinder.h"

int main(int ac, char **av) {
    t_info info;

    if (ac == 2) {
        mx_check_file(av[1]);
        mx_parse_file(av[1], &info);
        mx_algorithm(&info);
    }
    else
        mx_throw_error(USAGE);
}
