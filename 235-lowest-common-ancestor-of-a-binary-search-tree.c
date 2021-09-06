#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *
lowest_ancestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (NULL != root) {
        if (p == root || q == root) {
            return root;
        } else if (p->val < root->val && q->val > root->val) {
            return root;
        } else if (q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val) {
            root = root->right;
        }
    }
    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val < q->val) {
        return lowest_ancestor(root, p, q);
    } else {
        return lowest_ancestor(root, q, p);
    }
}
