#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void min_leaf_len(struct TreeNode *root, int depth, int *min) {
    if (NULL == root) {
        return;
    }
    if (NULL == root->left && NULL == root->right) {
        *min =  (depth+1 < *min ? depth+1 : *min);
        return ;
    }
    min_leaf_len(root->left, depth+1, min);
    min_leaf_len(root->right, depth+1, min);
}

int minDepth(struct TreeNode* root){
    int min = 65536;
    if (NULL == root) {
        return 0;
    }
    min_leaf_len(root, 0, &min);
    return min;
}

