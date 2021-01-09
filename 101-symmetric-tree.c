#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_same(struct TreeNode* p, struct TreeNode* q){
    if (NULL == p && NULL == q) {
        return true;
    } else if (NULL != p && NULL != q && p->val == q->val) {
        return is_same(p->left, q->right) && is_same(p->right, q->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode *root){
    return is_same(root, root);
}

