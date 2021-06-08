#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void
kth_small(struct TreeNode *root, int k, int *count, int *val) {
    if (NULL == root || k == *count) {
        return ;
    }
    kth_small(root->left, k, count, val);
    *count += 1;
    if (*count == k) {
        *val = root->val;
        return ;
    }
    kth_small(root->right, k, count, val);
}

int kthSmallest(struct TreeNode* root, int k){
    int count = 0;
    int val = -1;
    kth_small(root, k, &count, &val);
    return val;
}
