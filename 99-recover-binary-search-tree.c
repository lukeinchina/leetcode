#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define reversed_check(prev, x, y) do { \
    if (NULL != *prev && (*prev)->val > root->val) { \
        if (NULL == *x) { \
            *x = *prev; \
        } \
        *y = root; \
    } \
} while(0);

void find_exchange(struct TreeNode *root, struct TreeNode **prev, 
        struct TreeNode **x, struct TreeNode **y) {
    if (NULL == root) {
        return;
    }
    find_exchange(root->left, prev, x, y);
    reversed_check(prev, x, y);
    *prev = root;
    find_exchange(root->right, prev, x, y);
}

void recoverTree(struct TreeNode* root){
    int tmp;
    struct TreeNode *prev = NULL;
    struct TreeNode *x = NULL;
    struct TreeNode *y = NULL;
    find_exchange(root, &prev, &x, &y);
    if (NULL != x && NULL != y) {
        tmp    = x->val;
        x->val = y->val;
        y->val = tmp;
    }
}

void tree_print_in_order(const struct TreeNode *root) {
    if (NULL != root) {
        tree_print_in_order(root->left);
        printf("%d\t", root->val);
        tree_print_in_order(root->right);
    }

}
void tree_print(const struct TreeNode *root) {
    if (NULL != root) {
        printf("%d\t", root->val);
        tree_print(root->left);
        tree_print(root->right);
    }
}

int
main(int argc, char *argv[]) {
    // int nums[] = {1, 3, 0, 0, 2};
    // struct TreeNode *root= create_full_tree(nums, 5);
    tree_print(root);
    printf("\n");
    recoverTree(root);
    tree_print_in_order(root);
    printf("\n");
    return 0;
}
