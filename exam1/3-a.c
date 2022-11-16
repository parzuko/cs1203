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

void prefixPrint(struct ReverseBST *root) {
    if (root == NULL) {
        return;
    }
    
    printf(" %d", root->value);
    prefixPrint(root->left);
    prefixPrint(root->right);
}

// void print2DUtil(struct ReverseBST* root, int space)
// {
//     // Base case
//     if (root == NULL)
//         return;
 
//     // Increase distance between levels
//     space += COUNT;
 
//     // Process right child first
//     print2DUtil(root->right, space);
 
//     // Print current node after space
//     // count
//     printf("\n");
//     for (int i = COUNT; i < space; i++)
//         printf(" ");
//     printf("%d\n", root->value);
 
//     // Process left child
//     print2DUtil(root->left, space);
// }
 
// // Wrapper over print2DUtil()
// void print2D(struct ReverseBST* root)
// {
//     // Pass initial space count as 0
//     print2DUtil(root, 0);
// }



int main() {
    int array[] = {5, 2, 3, 7, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);
    struct ReverseBST *root = arrayToReverseBST(array, size);
    
    prefixPrint(root);
    printf("\n");
    return 0;
}