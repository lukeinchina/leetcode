#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *root;
    int mid = (numsSize - 1) >> 1;
    if (numsSize <= 0) {
        return NULL;
    }
    root      = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums+mid+1, numsSize-mid-1);
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
    int nums[] = {-10,-3,0,5,9};
    struct TreeNode *root = sortedArrayToBST(nums, sizeof(nums)/sizeof(nums[0]));
    print_tree(root);
    printf("\n");
    return 0;
}
