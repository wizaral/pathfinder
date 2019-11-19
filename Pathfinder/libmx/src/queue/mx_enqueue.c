#include "libmx.h"

void mx_enqueue(t_queue* queue, void* item) {
    if (queue && queue->array && item) {
        if (queue->size) {
            if (queue->size < queue->capacity) {
                if (queue->pointer2 + 1 == queue->capacity) {
                    queue->pointer2 = 0;
                    queue->array[queue->pointer2] = item;  //memcpy
                    ++queue->size;
                } else {
                    ++queue->pointer2;
                    queue->array[queue->pointer2] = anElement; //memcpy
                    ++queue->size;
                }
            } else if (queue->size == queue->capacity) {
                int tmp_capacity = 1.5 * queue->capacity;
                int* tmp = new int[tmp_capacity];   // malloc

                if (queue->pointer2 < queue->pointer1) {
                    for (int i = 0; i < queue->capacity - queue->pointer1; i++)
                        tmp[i] = queue->array[queue->pointer1 + i];
                    for (int i = 0; i <= pointer2; i++)
                        tmp[i + capacity - pointer1] = array[i];
                } else {
                    for (int i = 0; i < capacity; i++)
                        tmp[i] = array[i];
                }
                delete[] array;
                array = tmp;
                capacity = tmp_capacity;

                pointer2++;
                array[pointer2] = anElement;
                size++;
            }
        } else {
            array[pointer2] = anElement;
            size++;
        }
    }
}
