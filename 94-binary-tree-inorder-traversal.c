#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int tree_count(const struct TreeNode *root) {
    if (NULL == root) {
        return 0;
    } else {
        return 1 + tree_count(root->left) + tree_count(root->right);
    }
}

void get_in_order(const struct TreeNode *root, int *nums, int *index) {
    if (NULL == root) {
        return;
    }
    get_in_order(root->left, nums, index);
    nums[*index] = root->val;
    *index += 1;
    get_in_order(root->right, nums, index);
    return ;
}
int* 
inorderTraversal(struct TreeNode* root, int* returnSize){
    int *nums, index = 0;
    *returnSize = tree_count(root);
    if (0 == *returnSize) {
        return NULL;
    }
    nums = (int *)malloc(sizeof(int) * *returnSize);
    get_in_order(root, nums, &index);
    return nums;
}


int
main(void) {
    size_t i;
    int size, *p, nums[] = {2, 3, 1, 4};
    struct TreeNode *root = NULL;
    for (i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    p = inorderTraversal(root, &size);
    print_array(p, size);
    return 0;
}
