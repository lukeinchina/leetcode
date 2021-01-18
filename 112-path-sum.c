#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum){
    int left;
    if (NULL == root) {
        return false;
    }
    left = sum - root->val;
    if (NULL == root->left && NULL == root->right) {
        return 0 == left;
    }
    return hasPathSum(root->left, left) || hasPathSum(root->left, left);
}
