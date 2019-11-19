#include "libmx.h"

void mx_delete_queue(t_queue **queue) {
    if (queue && *queue) {
        if (malloc_size((*queue)->array))
            free((*queue)->array);
        if (malloc_size(*queue))
            free(*queue);
        *queue = NULL;
    }
}
