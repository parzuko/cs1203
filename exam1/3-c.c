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


// count how many numbers lie in between these two integers x and
// y. If x, y or both x and y don’t exist in the BST, return -1.
int sortedDistance(struct ReverseBST *root, int x, int y) {
    if (root == NULL) {
        return -1;
    }
    struct ReverseBST *node_x = find_node(root, x);
    struct ReverseBST *node_y = find_node(root, y);
    if (node_x == NULL || node_y == NULL) {
        return -1;
    }
    int count = 0;
    if (x < y) {
        while (node_x->value != node_y->value) {
            count++;
            node_x = find_node(root, node_x->value + 1);
        }
    } else {
        while (node_x->value != node_y->value) {
            count++;
            node_x = find_node(root, node_x->value - 1);
        }
    }
    return count - 1;
}


int main() {
    int array[] = {5, 2, 3, 7, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);
    struct ReverseBST *root = arrayToReverseBST(array, size);
    
    printf("Distance is %d\n", sortedDistance(root, 2, 8));
    return 0;
}