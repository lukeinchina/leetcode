#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "./common/base_type.h"

bool by_in_order(struct TreeNode *root, struct TreeNode **prev) {
    if (NULL == root) {
        return true;
    }
    bool left = by_in_order(root->left, prev);
    if (NULL != *prev && (*prev)->val >= root->val) {
        return false;
    } 
    *prev = root;
    bool right = by_in_order(root->right, prev);
    return left && right;
}

bool is_valid_bst(struct TreeNode *root, int *min, int *max) {
    bool left  = true;
    bool right = true;
    if (NULL == root->left && NULL == root->right) {
        *min = *max = root->val;
        return true;
    } 
    int l_min, l_max, r_min, r_max;
    if (NULL == root->right) {
        left = is_valid_bst(root->left, &l_min, &l_max);
        *min = l_min;
        return (left && root->val > l_max);
    } else if (NULL == root->left) {
        right = is_valid_bst(root->right, &r_min, &r_max);
        *max = r_max;
        return (right && root->val < r_min);
    } else {
        left  = is_valid_bst(root->left, &l_min, &l_max);
        right = is_valid_bst(root->right, &r_min, &r_max);
        *min  = l_min;
        *max  = r_max;
        return (left && right && l_max < root->val && root->val < r_min);
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    /*
    int min, max;
    return NULL == root || is_valid_bst(root, &min, &max);
    */
    struct TreeNode *prev = NULL;
    return by_in_order(root, &prev);
}

/* size 必须是2^n - 1.    0表示空值 */
struct TreeNode *
create_full_tree(const int *nums, int size) {
    int i;
    struct TreeNode **pp = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * size);
    for (i = 0; i < size; i++) {
        if (0 == nums[i]) {
            pp[i] = NULL;
        } else {
            pp[i] = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
            pp[i]->val = nums[i];
        }
    }

    for (i = size-1; i > 0; i -= 2) {
        int parent = i/2-1;
        if (nums[parent] == 0) {
            continue;
        }
        pp[parent]->left  = pp[i-1];
        pp[parent]->right = pp[i];
    }

    return pp[0];
}
int
main(int argc, char *argv[]) {
    int nums[] = {5, 3, 7, 2, 4, 6, 9};
    // int nums[] = {2, 1, 3};
    struct TreeNode *root= create_full_tree(nums, 7);
    tree_print_in_order(root);
    printf("\n");
    printf("%d\n", isValidBST(root));
    return 0;
}
