#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
};

/*
* Reverses the linked list in place.
*/
void reverse_linked_list(struct LinkedListNode **head) {
    struct LinkedListNode *prev = NULL;
    struct LinkedListNode *current = *head;
    struct LinkedListNode *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
* Reverses the linked list in place, till a given range.
*/
void reverse_till_k(struct LinkedListNode **head, int k) {
    int iterator = 1;
    struct LinkedListNode *dummy_head = *head;
    while (iterator < k && dummy_head != NULL) {
        dummy_head = dummy_head->next;
        iterator++;
    }

    // store the next node of the kth node
    struct LinkedListNode *saved_tail = dummy_head->next;
    dummy_head->next = NULL;

    reverse_linked_list(head);
    
    // Get to end of reversed linked list
    dummy_head = *head;
    while (dummy_head->next != NULL) {
        dummy_head = dummy_head->next;
    }
    dummy_head->next = saved_tail;
}



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

int main(void) {
    int length;
    printf("Reverse Linked List Algorithm\n");
    printf("Enter the number of elements in your list: ");
    scanf("%d", &length);

    struct LinkedListNode *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    int k;
    printf("Enter the number of elements you want to reverse: ");
    scanf("%d", &k);

    printf("Original list: ");
    print_linked_list(head);

    reverse_till_k(&head, k);
    printf("Reversed list: ");
    print_linked_list(head);
}