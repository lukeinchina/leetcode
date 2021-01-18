#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
    struct Node *left, *prev, *r = root;
    if (NULL == root) {
        return NULL;
    }

    for (left = root->left; NULL != left; left = left->left) {
        prev = NULL;
        for (; NULL != root; root = root->next) {
            root->left->next = root->right;
            if (NULL != prev) {
                prev->next = root->left;
            }
            prev = root->right;
        }
        root = left; /* next level */
    }
    return r;
}
