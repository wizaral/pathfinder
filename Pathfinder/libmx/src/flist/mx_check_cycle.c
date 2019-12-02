#include "libmx.h"

void mx_check_cycle(t_list *list) {
    t_list_node *slow = list ? list->head : NULL;
    t_list_node *fast = list ? list->head->next : NULL;
    t_list_node *finder = list ? list->head : NULL;

    if (list->head && list->tail) {
        if (list->head == list->tail) {
            list->head->next = list->tail->next = NULL;
            return;
        }

        for (; slow && fast && slow != fast; slow = slow->next)
            (fast = fast->next) ? fast = fast->next : fast;

        if (slow && fast) {
            for (fast = fast->next; finder != fast; fast = fast->next)
                finder = finder->next, slow = slow->next;
            slow->next = NULL;
        }
    }
    mx_check_size(list);
}
