#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
};

/*
* Prints the linked list 
*/
void print_linked_list(struct LinkedListNode *head) {
    struct LinkedListNode *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

/*
* Insert a new node at the end of the linked list.
*/
void append_node(struct LinkedListNode **head, int value) {
    struct LinkedListNode *new_node = malloc(sizeof(struct LinkedListNode));
    new_node->value = value;
    new_node->next = NULL;

    // Incase empty list 
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct LinkedListNode *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

struct LinkedListNode* get_partition(struct LinkedListNode *start, struct LinkedListNode *end) {

    struct LinkedListNode *pivot = start;
    struct LinkedListNode *current = start;

    while (current != end) {
        if (current->value < end->value) {
            pivot = start;

            int temp = pivot->value;
            start->value = current->value;
            current->value = temp;

            start = start->next;
        }
        current = current->next;
    }
    
    int temp = start->value;
    start->value = end->value;
    end->value = temp;
    return pivot;
}

void quick_sort(struct LinkedListNode *start, struct LinkedListNode *end) {
    if (start == end) {
        return;
    }
    struct LinkedListNode *partition = get_partition(start, end);
    quick_sort(start, partition);
    quick_sort(partition->next, end);
}


int main (void) {
    int length;
    printf("Quick Sort Linked List Algorithm\n");
    printf("Enter the number of elements in your list: ");
    scanf("%d", &length);

    struct LinkedListNode *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    printf("The unsorted linked list is: ");
    print_linked_list(head);

    struct LinkedListNode *tail_node = head;
    while (tail_node->next != NULL) {
        tail_node = tail_node->next;
    }

    quick_sort(head, tail_node);

    printf("The sorted linked list is: ");
    print_linked_list(head);
}