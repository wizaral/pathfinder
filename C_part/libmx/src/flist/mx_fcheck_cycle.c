#include "libmx.h"

void mx_fcheck_cycle(t_flist *list) {
    if (list && list->head && list->tail) {
        if (list->head != list->tail) {
            t_flist_node *slow = list->head;
            t_flist_node *fast = slow->next;
            t_flist_node *finder = slow;

            for (; slow && fast && slow != fast; slow = slow->next)
                (fast = fast->next) ? (fast = fast->next) : fast;
            if (slow && fast) {
                for (fast = fast->next; finder != fast; fast = fast->next) {
                    finder = finder->next;
                    slow = slow->next;
                }
                slow->next = NULL;
            }
        }
        else
            list->head->next = list->tail->next = NULL;
        mx_fcheck_size(list);
    }
}
