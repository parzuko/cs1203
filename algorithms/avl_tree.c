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

struct AVLTreeNode *insert_node(struct AVLTreeNode *root, int val) {
    if (root == NULL) {
        return create_node(val);
    }

    if (val < root->value) {
        root->left = insert_node(root->left, val);
    } else if (val > root->value) {
        root->right = insert_node(root->right, val);
    } else {
        return root;
    }

    root->height = 1 + max(fetch_height(root->left), fetch_height(root->right));

    int height_diff = get_tree_height_diff(root);

    // left left case
    if (height_diff > 1 && val < root->left->value) {
        return right_rotate(root);
    }

    // right right case
    if (height_diff < -1 && val > root->right->value) {
        return left_rotate(root);
    }

    // left right case
    if (height_diff > 1 && val > root->left->value) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // right left case
    if (height_diff < -1 && val < root->right->value) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void print_tree(struct AVLTreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    print_tree(root->left);
    print_tree(root->right);
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