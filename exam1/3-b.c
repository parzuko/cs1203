#include <stdio.h>
#include <stdlib.h>

struct ReverseBST {
    int value;
    struct ReverseBST *left;
    struct ReverseBST *right;
};

struct ReverseBST *createNode(int value) {
    struct ReverseBST *node = (struct ReverseBST *)malloc(sizeof(struct ReverseBST));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int cmpfnc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

struct ReverseBST *createBST(int *array, int size) {
    if (size == 0) {
        return NULL;
    }
    qsort(array, size, sizeof(int), cmpfnc);
    struct ReverseBST *root = createNode(array[size / 2]);
    root->left = createBST(array, size / 2);
    root->right = createBST(array + size / 2 + 1, size - size / 2 - 1);
    return root;
}

struct ReverseBST *invertBinaryTree(struct ReverseBST *root) {
    if (root == NULL) {
        return NULL;
    }

    struct ReverseBST *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    return root;
}

struct ReverseBST *arrayToReverseBST(int *array, int size) {
    struct ReverseBST *root = createBST(array, size);
    return invertBinaryTree(root);   
}

struct ReverseBST *find_node(struct ReverseBST *root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->value == target) {
        return root;
    }
    if (root->value < target) {
        return find_node(root->left, target);
    }
    return find_node(root->right, target);
}

void successorReverseBST(struct ReverseBST *root, int value) {
    struct ReverseBST *node = find_node(root, value);
    if (node == NULL) {
        printf("Pudding\n");
        return;
    }
    
    struct ReverseBST *successor = NULL;
    struct ReverseBST *current = root;
    while (current != NULL) {
        if (node->value < current->value) {
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (successor == NULL) {
        printf("Hamburger\n");
    } else {
        printf("%d\n", successor->value);
    }
}


int main() {
    int array[] = {5, 2, 3, 7, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);
    struct ReverseBST *root = arrayToReverseBST(array, size);
    
    successorReverseBST(root, 8);
    return 0;
}