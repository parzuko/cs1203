#include <stdio.h>
#include <stdlib.h>

int dynamic_array() {
    int *a;
    int i, n, val;
    
    n = 3;
    a = (int *) malloc(n * sizeof(int));

    i = 0;
    scanf("%d", &val);
    while (val > 0) {
        a[i] = val;
        i += 1;
        if (i >= n) {
            n *= 2;
            a = (int *) realloc(a, n * sizeof(int));
        }
        scanf("%d", &val);
    }
    // shrink extra spaces
    n = i;
    a = (int *) realloc(a, n * sizeof(int));
    
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("Done\n");

    return 0;
}

struct LinkedListNode {
    int val;
    struct LinkedListNode *next;
};
typedef struct LinkedListNode Node;

int main(int argc, char **argv) { 
    int i, val;
    Node *head = NULL;
    
    i = 0;
    scanf("%d", &val);
    while (val > 0) {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->val = val; // or (*new_node).val = val;
        new_node->next = NULL;

        // will do something next class!

        head->next = new_node;

        i += 1;
        scanf("%d", &val);
    }
    return 0;
}