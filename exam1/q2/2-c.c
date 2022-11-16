#include <stdio.h>
#include <stdlib.h>

struct ReversalNode {
    int value;
    int k;
    struct ReversalNode *next;
    struct ReversalNode *nextK;
};

// https://www.geeksforgeeks.org/generating-random-number-range-c/
int generateRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// create a node
struct ReversalNode *createNode(int value) {
    struct ReversalNode *node = (struct ReversalNode *) malloc(sizeof(struct ReversalNode));
    node->k = generateRandom(2, 5);
    node->value = value;
    node->next = NULL;
    node->nextK = NULL;
    return node;
}

struct ReversalNode *arrayToLLWithnextK(int *array, int size) {
    if (size == 0) {
        return NULL;
    }
    struct ReversalNode *head = createNode(array[0]);
    struct ReversalNode *current = head;
    
    // hashmap to store the nodes at each index
    struct ReversalNode *nodes[size];
    nodes[0] = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(array[i]);
        current = current->next;
        nodes[i] = current;
    }

    // set the nextK pointers
    for (int i = 0; i < size; i++) {
        if (i + nodes[i]->k < size) {
            nodes[i]->nextK = nodes[i + nodes[i]->k];
        }
    }
    return head;
}

void printLinkedList(struct ReversalNode *head) {
    struct ReversalNode *current = head;

    while (current != NULL) {
        printf("Value =  %d ", current->value);
        if (current->nextK != NULL) {
            printf("K = %d and nextK value is %d \n", current->k, current->nextK->value);
        } else {
            printf("K = %d and nextK value is NULL \n", current->k);
        }
        current = current->next;
    }
}


int main (void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct ReversalNode *head = arrayToLLWithnextK(array, 9);
    printLinkedList(head);
    return 0;
}