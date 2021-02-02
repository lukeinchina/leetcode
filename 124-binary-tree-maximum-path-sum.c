#include <stdio.h>

#include "common/base_type.h"

int 
max_sum(struct TreeNode *root, int *max, int *max_item) {
    int left, right, sum;
    if (NULL == root) {
        return 0;
    }
    if (*max_item < root->val) {
        *max_item = root->val;
    }

    left = max_sum(root->left, max, max_item);
    right = max_sum(root->right, max, max_item);

    sum  = (left > right ? left : right) + root->val;
    *max = (left + right + root->val > *max ? left + right + root->val : *max);

    return (sum > 0 ? sum : 0);
}

int maxPathSum(struct TreeNode* root){
    int max = -65536;
    int max_item = max;
    max_sum(root, &max, &max_item);
    return (max_item <= 0 ? max_item : max);
}

int
main(void) {
    struct TreeNode *root = NULL;
    int nums[] = {-1, -7, 15, 20, -10, 10};
    int i;
    for (i = 0; i < sizeof(nums) /sizeof(nums[0]); i++) {
    // for (i = 0; i < 1; i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n----\n");
    printf("%d\n", maxPathSum(root));
    return 0;
}
