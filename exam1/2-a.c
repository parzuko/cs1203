#include <stdio.h>
#include <stdlib.h>

struct ReversalNode {
    int value;
    struct ReversalNode *next;
    struct ReversalNode *next2;
};

// create a node
struct ReversalNode *createNode(int value) {
    struct ReversalNode *node = (struct ReversalNode *) malloc(sizeof(struct ReversalNode));
    node->value = value;
    node->next = NULL;
    node->next2 = NULL;
    return node;
}

struct ReversalNode *arrayToLLWithNext2(int *array, int size) {
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

    // set the next2 pointers
    for (int i = 0; i < size; i++) {
        if (i + 2 < size) {
            nodes[i]->next2 = nodes[i + 2];
        }
    }
    return head;
}

void printLL(struct ReversalNode *head) {
    struct ReversalNode *current = head;
    while (current != NULL) {
        printf("%d ", current->value);

        if (current->next2 != NULL) {
            printf("Next2 is -> (%d)\n", current->next2->value);
        } else {
            printf("Next2 is -> (NULL)\n");
        }

        current = current->next;
    }
    printf("\n");
}


int main (void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct ReversalNode *head = arrayToLLWithNext2(array, 9);
    printLL(head);
    return 0;
}