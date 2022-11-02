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
* Given pointer to the head node of a linked list, inserts new node, infront.
*/
void append_left(struct LinkedListNode ** head, int new_val) {
    struct LinkedListNode* new_node = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    new_node->value = new_val;
    new_node->next = *head;
    *head = new_node;
}

/*
* Given previous node, inserts new node after the given node.
*/
void insert_after_node(struct LinkedListNode *prev_node, int new_val) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct LinkedListNode* new_node = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    new_node->value = new_val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/*
* Given pointer to the head node of a linked list and a target, deletes the target in linked list.
*/
void delete_given_node(struct LinkedListNode **head, int target) {
    struct LinkedListNode *current = *head;
    struct LinkedListNode *prev = NULL;

    // If head node has the target value
    if (current != NULL && current->value == target) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the target value, and update prev node
    while (current != NULL && current->value != target) {
        prev = current;
        current = current->next;
    }

    // If target value was not present in linked list
    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

int main(void) {
    struct LinkedListNode *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 4);
    append_node(&head, 3);
    
    printf("Linked list before deleting: ");
    print_linked_list(head);
    
    printf("Linked list after deleting: ");
    delete_given_node(&head, 4);
    print_linked_list(head);

    append_left(&head, 0);
    insert_after_node(head->next, 5);
    
    printf("Linked list after inserting: ");
    print_linked_list(head);
    return 0;
}