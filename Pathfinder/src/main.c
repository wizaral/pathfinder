#include "pathfinder.h"

// #include <stdio.h>

// void print(t_info *info) {
//     printf("Size: %zu\n", info->size);

//     for (size_t i = 0; i < info->size; ++i)
//         printf("name %zu: %s\n", i, info->names[i]);
//     for (size_t i = 0; i < info->size; ++i)
//         printf("visited %zu: %i\n", i, info->visited[i]);
//     for (size_t i = 0; i < info->size; ++i)
//         printf("name %zu: %i\n", i, info->distances[i]);

//     for (size_t i = 0; i < info->size; ++i) {
//         printf("SIZE::: %zu\n", info->graph[i].size);
//         for (size_t j = 0; j < info->graph[i].size; ++j)
//             printf("%zu -> %zu : %i\n", i, ((t_pair *)mx_at(&info->graph[i], j))->island, ((t_pair *)mx_at(&info->graph[i], j))->distance);
//     }
// }

int main(int ac, char **av) {
    t_info info;

    if (ac == 2) {
        mx_init_info(&info, mx_check_file(av[1]));
        mx_parse_file(&info, mx_file_to_str(av[1]));
        mx_algorithm(&info);
        // mx_delete_info(&info);
    }
    else
        mx_throw_usage_error();
    // system("leaks -q pathfinder");
}