#include <stdio.h>

#include "common/base_type.h"

/* 返回值表示是否平衡 */
bool tree_depth(struct TreeNode *root, int *depth) {
    int l = 0;
    int r = 0;
    if (NULL != root) {
        if (!tree_depth(root->left, &l)) {
            return false;
        }
        if (!tree_depth(root->right, &r)) {
            return false;
        }
    }
    *depth = (l > r ? l : r) + 1;
    return (l == r || l+1 == r || r+1 == l);
}

bool isBalanced(struct TreeNode* root){
    int depth;
    return tree_depth(root, &depth);
}

int
main(int argc, char *argv[]) {
    int i;
    int array[] = {9,7,5,3,8, 6, 4};
    struct TreeNode *root = NULL;
    for (i = 0; i < 7; i++) {
        root = tree_insert(root, array[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    printf("%d\n", isBalanced(root));
    return 0;
}
