#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int i;
    struct TreeNode *root = NULL;
    if (0 >= inorderSize) {
        return NULL;
    }
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];
    for (i = 0; i < inorderSize && postorder[postorderSize-1] != inorder[i]; i++) {
    }
    root->left  = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder+i+1, inorderSize-i-1, postorder+i, postorderSize-i-1);
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
    int postorder[] = {9,15,7,20,3};
    int inorder[]  = {9,3,15,20,7};
    struct TreeNode *root = buildTree(inorder, 5, postorder, 5);
    print_tree(root);
    printf("\n");
    return 0;
}
