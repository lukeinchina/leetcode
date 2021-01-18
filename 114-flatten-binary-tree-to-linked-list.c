#include <stdio.h>
#include <stdlib.h>
#include "common/base_type.h"

struct TreeNode *
rotate(struct TreeNode *root) {
    struct TreeNode *last_l, *last_r;

    if (NULL == root->left && NULL == root->right) {
        return root;
    } else if (NULL == root->right) {
        root->right = root->left;
        root->left  = NULL;
        return rotate(root->right);
    }else if (NULL == root->left) {
        return rotate(root->right);
    }
    /*左右均有 */
    last_l = rotate(root->left);
    last_r = rotate(root->right);

    last_l->right = root->right;
    root->right   = root->left;
    root->left   = NULL;
    return last_r;
}   

void flatten(struct TreeNode* root){
    if (NULL != root) {
        rotate(root);
    }
}

int
main(void) {
    struct TreeNode *root = NULL;
    int nums[] = {4,5,6,2,1,3};
    int i;
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    flatten(root);
    tree_print_in_order(root);
    printf("\n");
    return 0;
}
