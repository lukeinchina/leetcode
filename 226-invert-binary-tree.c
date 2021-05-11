#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* 
invertTree(struct TreeNode* root){
    struct TreeNode *p;
    if (NULL == root) {
        return NULL;
    }else if (NULL == root->left && NULL == root->right) {
        return root;
    }
    p = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(p);
    return root;
}
