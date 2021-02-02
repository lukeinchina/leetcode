#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void sum_all_path(struct TreeNode *root, int *sum, int val) {
    if (NULL == root) {
        return ;
    }
    if (NULL == root->left && NULL == root->right) {
        *sum += val * 10 + root->val;
    } else {
        sum_all_path(root->left, sum, val * 10 + root->val);
        sum_all_path(root->right, sum, val * 10 + root->val);
    }
}

int sumNumbers(struct TreeNode* root){
    int sum = 0;
    sum_all_path(root, &sum, 0);
    return sum;
}
