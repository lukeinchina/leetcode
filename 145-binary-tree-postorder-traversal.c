#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void push_item(struct TreeNode *root, int *stack, int *top) {
    if (NULL == root) {
        return;
    }
    push_item(root->left, stack, top);
    push_item(root->right, stack, top);
    stack[*top] = root->val;
    *top += 1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int stack[102];
    int top = 0;
    int *result = NULL;
    push_item(root, stack, &top);

    *returnSize = top; 
    result = (int *)malloc(sizeof(int) * top);
    memcpy(result, stack, sizeof(stack[0]) * top);
    return result;
}
