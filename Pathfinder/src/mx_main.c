#include "pathfinder.h"

// for case with 17 islands
#undef VECTOR_DEFAULT_SIZE
#define VECTOR_DEFAULT_SIZE 32

void test(t_info *info) {
    info->size = 17;     // 4

    //=======================================================================//

    info->distances.bytes = sizeof(t_i64);
    info->distances.cap = VECTOR_DEFAULT_SIZE;
    info->distances.size = info->size;
    info->distances.arr = (t_i64 *)malloc(sizeof(t_i64) * VECTOR_DEFAULT_SIZE);

    for (size_t i = 0; i < info->size; ++i)
        *(t_i64 *)mx_at(&info->distances, i) = MX_INF;

    //=======================================================================//

    info->visited.bytes = sizeof(char);
    info->visited.cap = VECTOR_DEFAULT_SIZE;
    info->visited.size = info->size;
    info->visited.arr = (char *)malloc(sizeof(char) * VECTOR_DEFAULT_SIZE);

    for (size_t i = 0; i < info->size; ++i)
        *(char *)mx_at(&info->visited, i) = false;

    //=======================================================================//

    info->names.bytes = sizeof(char *);
    info->names.cap = VECTOR_DEFAULT_SIZE;
    info->names.size = info->size;
    info->names.arr = (char **)malloc(sizeof(char *) * VECTOR_DEFAULT_SIZE);

    // *((char **)mx_at(&info->names, 0)) = mx_strdup("Greenland");
    // *((char **)mx_at(&info->names, 1)) = mx_strdup("Bananal");
    // *((char **)mx_at(&info->names, 2)) = mx_strdup("Fraser");
    // *((char **)mx_at(&info->names, 3)) = mx_strdup("Java");

    char str[] = "A";
    for (int i = 0; i < 17; ++i, *str = i + 65)
        *(char **)mx_at(&info->names, i) = mx_strdup(str);

    //=======================================================================//

    info->routes.bytes = sizeof(t_vector);
    info->routes.cap = VECTOR_DEFAULT_SIZE;
    info->routes.size = 0;
    info->routes.arr = malloc(sizeof(t_vector) * VECTOR_DEFAULT_SIZE);

    //=======================================================================//

    info->parents.bytes = sizeof(t_vector);
    info->parents.cap = VECTOR_DEFAULT_SIZE;
    info->parents.size = info->size;
    info->parents.arr = malloc(sizeof(t_vector) * VECTOR_DEFAULT_SIZE);

    for (size_t i = 0; i < info->size; ++i) {
        ((t_vector *)mx_at(&info->parents, i))->cap = VECTOR_DEFAULT_SIZE;
        ((t_vector *)mx_at(&info->parents, i))->size = 0;
        ((t_vector *)mx_at(&info->parents, i))->bytes = sizeof(size_t);
        ((t_vector *)mx_at(&info->parents, i))->arr = malloc(sizeof(size_t) * VECTOR_DEFAULT_SIZE);
    }

    //=======================================================================//

    info->graph.bytes = sizeof(t_vector);
    info->graph.cap = VECTOR_DEFAULT_SIZE;
    info->graph.size = info->size;
    info->graph.arr = malloc(sizeof(t_vector) * VECTOR_DEFAULT_SIZE);

    for (size_t i = 0; i < info->size; ++i) {
        ((t_vector *)mx_at(&info->graph, i))->cap = VECTOR_DEFAULT_SIZE;
        ((t_vector *)mx_at(&info->graph, i))->size = 0;
        ((t_vector *)mx_at(&info->graph, i))->bytes = sizeof(t_pair);
        ((t_vector *)mx_at(&info->graph, i))->arr = malloc(sizeof(t_pair) * VECTOR_DEFAULT_SIZE);
    }

    // t_pair pair = {1, 8};
    // mx_push_backward(mx_at(&info->graph, 0), &pair);
    // pair.island = 2;
    // pair.dist = 10;
    // mx_push_backward(mx_at(&info->graph, 0), &pair);

    // pair.island = 0;
    // pair.dist = 8;
    // mx_push_backward(mx_at(&info->graph, 1), &pair);
    // pair.island = 2;
    // pair.dist = 3;
    // mx_push_backward(mx_at(&info->graph, 1), &pair);

    // pair.island = 0;
    // pair.dist = 10;
    // mx_push_backward(mx_at(&info->graph, 2), &pair);
    // pair.island = 1;
    // pair.dist = 3;
    // mx_push_backward(mx_at(&info->graph, 2), &pair);
    // pair.island = 3;
    // pair.dist = 5;
    // mx_push_backward(mx_at(&info->graph, 2), &pair);

    // pair.island = 2;
    // pair.dist = 5;
    // mx_push_backward(mx_at(&info->graph, 3), &pair);

    //=======================================================================//

    t_pair pair = {1, 2};
    mx_push_backward(mx_at(&info->graph, 0), &pair);
    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 0), &pair);
    pair.island = 3;
    mx_push_backward(mx_at(&info->graph, 0), &pair);

    pair.island = 0;
    mx_push_backward(mx_at(&info->graph, 1), &pair);
    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 1), &pair);
    pair.island = 6;
    mx_push_backward(mx_at(&info->graph, 1), &pair);
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 1), &pair);
    pair.dist = 1;
    pair.island = 4;
    mx_push_backward(mx_at(&info->graph, 1), &pair);

    pair.dist = 2;
    pair.island = 0;
    mx_push_backward(mx_at(&info->graph, 2), &pair);
    pair.island = 1;
    mx_push_backward(mx_at(&info->graph, 2), &pair);
    pair.island = 3;
    mx_push_backward(mx_at(&info->graph, 2), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 2), &pair);
    pair.dist = 1;
    pair.island = 4;
    mx_push_backward(mx_at(&info->graph, 2), &pair);
    pair.island = 5;
    mx_push_backward(mx_at(&info->graph, 2), &pair);

    pair.dist = 2;
    pair.island = 0;
    mx_push_backward(mx_at(&info->graph, 3), &pair);
    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 3), &pair);
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 3), &pair);
    pair.island = 10;
    mx_push_backward(mx_at(&info->graph, 3), &pair);
    pair.dist = 1;
    pair.island = 5;
    mx_push_backward(mx_at(&info->graph, 3), &pair);

    pair.island = 1;
    mx_push_backward(mx_at(&info->graph, 4), &pair);
    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 4), &pair);
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 4), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 4), &pair);

    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 5), &pair);
    pair.island = 3;
    mx_push_backward(mx_at(&info->graph, 5), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 5), &pair);
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 5), &pair);

    pair.dist = 2;
    pair.island = 1;
    mx_push_backward(mx_at(&info->graph, 6), &pair);
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 6), &pair);
    pair.island = 13;
    mx_push_backward(mx_at(&info->graph, 6), &pair);

    pair.island = 1;
    mx_push_backward(mx_at(&info->graph, 7), &pair);
    pair.island = 6;
    mx_push_backward(mx_at(&info->graph, 7), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 7), &pair);
    pair.island = 13;
    mx_push_backward(mx_at(&info->graph, 7), &pair);
    pair.dist = 1;
    pair.island = 4;
    mx_push_backward(mx_at(&info->graph, 7), &pair);
    pair.island = 11;
    mx_push_backward(mx_at(&info->graph, 7), &pair);

    pair.dist = 2;
    pair.island = 2;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.dist = 1;
    pair.island = 4;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 5;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 11;
    mx_push_backward(mx_at(&info->graph, 8), &pair);
    pair.island = 12;
    mx_push_backward(mx_at(&info->graph, 8), &pair);

    pair.dist = 2;
    pair.island = 3;
    mx_push_backward(mx_at(&info->graph, 9), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 9), &pair);
    pair.island = 10;
    mx_push_backward(mx_at(&info->graph, 9), &pair);
    pair.island = 15;
    mx_push_backward(mx_at(&info->graph, 9), &pair);
    pair.dist = 1;
    pair.island = 5;
    mx_push_backward(mx_at(&info->graph, 9), &pair);
    pair.island = 12;
    mx_push_backward(mx_at(&info->graph, 9), &pair);

    pair.dist = 2;
    pair.island = 3;
    mx_push_backward(mx_at(&info->graph, 10), &pair);
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 10), &pair);
    pair.island = 15;
    mx_push_backward(mx_at(&info->graph, 10), &pair);

    pair.dist = 1;
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 11), &pair);
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 11), &pair);
    pair.island = 13;
    mx_push_backward(mx_at(&info->graph, 11), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 11), &pair);

    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 12), &pair);
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 12), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 12), &pair);
    pair.island = 15;
    mx_push_backward(mx_at(&info->graph, 12), &pair);

    pair.dist = 2;
    pair.island = 6;
    mx_push_backward(mx_at(&info->graph, 13), &pair);
    pair.island = 7;
    mx_push_backward(mx_at(&info->graph, 13), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 13), &pair);
    pair.island = 16;
    mx_push_backward(mx_at(&info->graph, 13), &pair);
    pair.dist = 1;
    pair.island = 11;
    mx_push_backward(mx_at(&info->graph, 13), &pair);

    pair.dist = 2;
    pair.island = 8;
    mx_push_backward(mx_at(&info->graph, 14), &pair);
    pair.island = 13;
    mx_push_backward(mx_at(&info->graph, 14), &pair);
    pair.island = 15;
    mx_push_backward(mx_at(&info->graph, 14), &pair);
    pair.island = 16;
    mx_push_backward(mx_at(&info->graph, 14), &pair);
    pair.dist = 1;
    pair.island = 11;
    mx_push_backward(mx_at(&info->graph, 14), &pair);
    pair.island = 12;
    mx_push_backward(mx_at(&info->graph, 14), &pair);

    // pair.dist = 1;
    // pair.island = 12;
    mx_push_backward(mx_at(&info->graph, 15), &pair);
    pair.dist = 2;
    pair.island = 9;
    mx_push_backward(mx_at(&info->graph, 15), &pair);
    pair.island = 10;
    mx_push_backward(mx_at(&info->graph, 15), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 15), &pair);
    pair.island = 16;
    mx_push_backward(mx_at(&info->graph, 15), &pair);

    pair.island = 13;
    mx_push_backward(mx_at(&info->graph, 16), &pair);
    pair.island = 14;
    mx_push_backward(mx_at(&info->graph, 16), &pair);
    pair.island = 15;
    mx_push_backward(mx_at(&info->graph, 16), &pair);
}

int main(int ac, char **av) {
    t_info info;
    test(&info);

    if (ac && av) {
        // mx_check_file(av[1]);
        // mx_parse_file(av[1], &info);
        mx_algorithm(&info);
        // mx_delete_info(&info);
    }
    // else
    //     mx_throw_error(USAGE);
    // system("leaks -q pathfinder");
}
