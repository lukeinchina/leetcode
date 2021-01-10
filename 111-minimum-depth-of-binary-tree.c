#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root){
    int left, right;
    if (NULL == root) {
        return 0;
    }
    left  = minDepth(root->left);
    right = minDepth(root->right);
    return (left > right ? right : left) + 1;
}

