#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int lowest_ancestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, 
        struct TreeNode **anc) {
    int l, r;
    if (NULL == root || NULL != *anc) {
        return 0;
    }
    l = lowest_ancestor(root->left, p, q, anc);
    r = lowest_ancestor(root->right, p, q, anc);
    if (l && r && NULL == *anc) {
        *anc = root;
        return 1;
    }
    if (p == root || q == root) {
        if (l || r) {
            *anc = root;
        }
        return 1;
    }
    return (l || r);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *anc;
    lowest_ancestor(root, p, q, &anc);
    return anc;
}
