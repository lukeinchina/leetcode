#include <stdio.h>

#include <vector>

#include "common/base_type.h"

using namespace std;

void right_side_view(const TreeNode *root, int depth, vector<int> &rst) {
    if (NULL == root) {
        return;
    }
    if (depth == (int)rst.size()) {
        rst.push_back(root->val);
    }
    right_side_view(root->right, depth+1, rst);
    right_side_view(root->left, depth+1, rst);
}

vector<int> 
rightSideView(TreeNode* root) {
    vector<int> rst;
    right_side_view(root, 0, rst);
    for (size_t i = 0; i < rst.size(); i++) {
        printf("%d%c", rst[i], i+1 == rst.size() ? '\n' : '\t');
    }
    return rst;
}

int
main(void) {
    int nums[] = {8, 5, 10, 7, 4, 3, 2, 13, 12};
    struct TreeNode *root = NULL;
    int i;
    for (i = 0; i < sizeof(nums) / sizeof(nums[i]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    vector<int> rst = rightSideView(root);
    return 0;
}
