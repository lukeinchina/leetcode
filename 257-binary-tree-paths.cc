#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "common/base_type.h"

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
*/

using namespace std;

void 
tree_paths(TreeNode *root, int stack[], int top, vector<string> &all) {
    if (NULL == root) {
        return;
    } 
    stack[top++] = root->val;

    if (NULL == root->left && NULL == root->right) {
        int offset = 0;
        int len = 0;
        char path[256<<10];
        for (int i = 0; i < top; i++) {
            if (0 == i) {
                len = snprintf(path + offset, sizeof(path) - offset, "%d", stack[i]);
            } else {
                len = snprintf(path + offset, sizeof(path) - offset, "->%d", stack[i]);
            }
            offset += len;
        }
        all.push_back(path);
        return ;
    } else if (NULL == root->left) {
        tree_paths(root->right, stack, top, all);
    } else if (NULL == root->right) {
        tree_paths(root->left, stack, top, all);
    } else {
        tree_paths(root->right, stack, top, all);
        tree_paths(root->left, stack, top, all);
    }
    return;
}

    vector<string> binaryTreePaths(TreeNode* root) {
        int stack[128];
        vector<string> all;
        tree_paths(root, stack, 0, all);
        return all;
    }

int
main(int arg, char *argv[]) {
    struct TreeNode *root = NULL;
    root = tree_insert(root, 3);
    root = tree_insert(root, 2);
    root = tree_insert(root, 7);
    root = tree_insert(root, 4);
    root = tree_insert(root, 5);
    root = tree_insert(root, 10);
    root = tree_insert(root, 18);
    tree_print_in_order(root);   
    printf("\n");
    vector<string> all = binaryTreePaths(root);
    for (size_t i = 0; i < all.size(); i++) {
        printf("%s\n", all[i].c_str());
    }
    return 0;
}
