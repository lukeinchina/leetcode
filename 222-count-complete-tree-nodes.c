#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int left_most(struct TreeNode *root) {
    int n = 0;
    for (; NULL != root; root = root->left) {
        n += 1;
    }
    return n;
}

int countNodes(struct TreeNode* root){
    int l, r, count = 0;
    if (NULL == root) {
        return 0;
    }
    l = left_most(root->left);
    r = left_most(root->right);
    if (l == r) {
        count = (1 << l) + countNodes(root->right);
    } else {
        count = (1 << r) + countNodes(root->left);
    }
    return count;
}

