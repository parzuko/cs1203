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
// https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
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

void prefixPrint(struct ReverseBST *root) {
    if (root == NULL) {
        return;
    }
    
    printf(" %d", root->value);
    prefixPrint(root->left);
    prefixPrint(root->right);
}


int main() {
    int array[] = {5, 2, 3, 7, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);
    struct ReverseBST *root = arrayToReverseBST(array, size);
    
    prefixPrint(root);
    printf("\n");
    return 0;
}