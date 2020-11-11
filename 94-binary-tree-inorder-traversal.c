#include <stdio.h>
#include <stdlib.h>
#include "common/base_type.h"
/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int i, total;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int *array = (int *)malloc(sizeof(int) * 100);
    i = total = 0;
    stack[i++] = root;
    while (i > 0) {
        while (root->left != NULL) {
            root = root->left;
            stack[i++] = root;
        }
        root = stack[--i];
        array[total++] = root->val;
        printf("%d\n", root->val);
        if (NULL != root->right) {
            root = root->right;
            stack[i++] = root;
        }
    }
    free(stack);
    return array;
}

int main(void) {
    int array[] = {10, 5, 15, 3, 9, 20, 18, 6, 12, 16, 7, 8};
    struct TreeNode *root = NULL;
    int i;
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        root = tree_insert(root, array[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    inorderTraversal(root, NULL);
    return 0;
}
