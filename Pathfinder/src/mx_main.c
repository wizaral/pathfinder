#include "header.h"

int main(int ac, char **av) {
    t_graph graph;

    if (ac == 2) {
        mx_check_file(av[1]);
        mx_parse_file(av[1], &graph);
        mx_find_route(&graph);
    }
    else
        mx_throw_error(USAGE);
}
