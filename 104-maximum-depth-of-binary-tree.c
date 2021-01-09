#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    int left, right;
    if (NULL == root) {
        return 0;
    }
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}
