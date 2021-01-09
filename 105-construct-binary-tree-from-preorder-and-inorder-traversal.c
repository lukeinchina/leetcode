#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int i;
    struct TreeNode *root = NULL;
    if (0 >= preorderSize) {
        return NULL;
    }
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    for (i = 0; i < inorderSize && preorder[0] != inorder[i]; i++) {
    }
    root->left = buildTree(preorder+1, i, inorder, i);
    root->right = buildTree(preorder+i+1, preorderSize-i-1, inorder+i+1, inorderSize-i-1);
    return root;
}

void print_tree(struct TreeNode *root) {
    if (NULL != root) {
        print_tree(root->left);
        printf("%d\t", root->val);
        print_tree(root->right);
    }
}

int
main(int argc, char *argv[]) {
    int preorder[] = {3,9,20,15,7};
    int inorder[]  = {9,3,15,20,7};
    struct TreeNode *root = buildTree(preorder, 5, inorder, 5);
    print_tree(root);
    printf("\n");
    return 0;
}
