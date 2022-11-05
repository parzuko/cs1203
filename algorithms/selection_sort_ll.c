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

/*
* Selection Sort Algorithm on a Linked List
*/
void selection_sort(struct LinkedListNode **head) {
    struct LinkedListNode *current = *head;
    while (current != NULL) {
        struct LinkedListNode *min = current;
        struct LinkedListNode *j = current->next;
        while (j != NULL) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }
        // swap with min with i
        int temp = current->value;
        current->value = min->value;
        min->value = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
    printf("Selection Sort Linked List Algorithm\n");
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

    selection_sort(&head);

    printf("The sorted linked list is: ");
    print_linked_list(head);
}