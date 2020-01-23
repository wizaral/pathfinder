#include "pathfinder.h"

int main(int ac, char **av) {
    if (ac == 2) {
        t_info info;
        char *names[2] = {0};
        t_file file = {NULL, NULL, {0, 0}, {0, 0}, 2, names, 0, 0};

        mx_init_info(&info, mx_check_file(av[1]));
        file.file = file.copy = mx_file_to_str(av[1]);
        mx_parse_file(&info, &file);
        free(file.copy);
        if (info.size)
            mx_algorithm(&info);
        mx_delete_info(&info);
    }
    else
        mx_throw_usage_error();
}
