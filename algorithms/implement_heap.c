#include <stdio.h>
#include <stdlib.h>

struct MinHeapQueue {
    int *numbers;
    int max_size;
    int current_length;
};

int get_parent(int index) {
    return (index - 1) / 2;
}

int get_left_child(int index) {
    return (2 * index) + 1;
}

int get_right_child(int index) {
    return (2 * index) + 2;
}

int get_min_child(struct MinHeapQueue* pq) {
    // Min Element of a min heap is always the root element
    return pq->numbers[0];
}

struct MinHeapQueue* insert(struct MinHeapQueue* pq, int value) {
    if (pq->current_length == pq->max_size) {
        printf("Heap is full. Cannot insert %d", value);
        return pq; 
    }
    pq->numbers[pq->current_length] = value;
    pq->current_length++;
    int current_index = pq->current_length - 1;
    int parent_index = get_parent(current_index);
    while (parent_index >= 0 && pq->numbers[parent_index] > pq->numbers[current_index]) {
        int temp = pq->numbers[parent_index];
        pq->numbers[parent_index] = pq->numbers[current_index];
        pq->numbers[current_index] = temp;
        current_index = parent_index;
        parent_index = get_parent(current_index);
    }
    return pq;
}