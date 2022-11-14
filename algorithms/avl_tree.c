#include <stdio.h>
#include <stdlib.h>

struct AVLTreeNode {
    int value;
    int height;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
};

int max(int val1, int val2) {
    if (val1 > val2) {
        return val1;
    }
    return val2;
}

int fetch_height(struct AVLTreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

struct AVLTreeNode *create_node(int value) {
    struct AVLTreeNode *new_node = (struct AVLTreeNode *)malloc(sizeof(struct AVLTreeNode));
    new_node->value = value;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int get_tree_height_diff(struct AVLTreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    return fetch_height(node->left) - fetch_height(node->right);
}

struct AVLTreeNode *right_rotate(struct AVLTreeNode *node) {
    // get nodes
    struct AVLTreeNode *left_subtree = node->left;
    struct AVLTreeNode *right_of_left_subtree = left_subtree->left;

    // rotate
    left_subtree->right = node;
    node->left = right_of_left_subtree;

    // update heights
    node->height = 1 + max(fetch_height(node->right), fetch_height(node->left));
    left_subtree->height =  1 + max(fetch_height(left_subtree->right), fetch_height(left_subtree->left));

    return left_subtree;
}

struct AVLTreeNode *left_rotate(struct AVLTreeNode *node) {
    // get nodes
    struct AVLTreeNode *right_subtree = node->right;
    struct AVLTreeNode *left_of_right_subtree = right_subtree->left;

    // rotate
    right_subtree->left = node;
    node->right = left_of_right_subtree;

    // update heights
    node->height = 1 + max(fetch_height(node->right), fetch_height(node->left));
    right_subtree->height =  1 + max(fetch_height(right_subtree->right), fetch_height(right_subtree->left));

    return right_subtree;
}

struct AVLTreeNode *insert_node(struct AVLTreeNode *node, int val) {
    if (node == NULL) {
        return create_node(val);
    }

    if (val < node->value) {
        node->left = insert_node(node->left, val);
    } else if (val > node->value) {
        node->right = insert_node(node->right, val);
    } else {
        return node;
    }

    node->height = 1 + max(fetch_height(node->left), fetch_height(node->right));

    int height_diff = get_tree_height_diff(node);

    // left left case
    if (height_diff > 1 && val < node->left->value) {
        return right_rotate(node);
    }

    // right right case
    if (height_diff < -1 && val > node->right->value) {
        return left_rotate(node);
    }

    // left right case
    if (height_diff > 1 && val > node->left->value) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // right left case
    if (height_diff < -1 && val < node->right->value) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void print_tree(struct AVLTreeNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    print_tree(node->left);
    print_tree(node->right);
}

int main (void) {
    struct AVLTreeNode *root = NULL;
    
    int k = -1;
    for (int i = 0; i < 100; i = i + 8) {
        root = insert_node(root, i * k);
        k = k * -1;
    }
    
    print_tree(root);
    printf("\n");

    return 0;
}