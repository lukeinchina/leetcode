#include <stdio.h>
#include <stdlib.h>
#include "common/stack.h"
#include "common/base_type.h"

/* 执行用时： 44 ms , 在所有 C 提交中击败了 97.44% 的用户
内存消耗： 16.3 MB , 在所有 C 提交中击败了 100.00% 的用户
*/
typedef struct {
    Stack stack;

}BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *it = (BSTIterator *)calloc(1, sizeof(BSTIterator));
    stack_init(&it->stack);
    for (; NULL != root; root = root->left) {
        stack_push(&it->stack, root);
    }

    return it;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode *root = (struct TreeNode *)stack_pop(&(obj->stack));
    int val = root->val;
    for (root = root->right; NULL != root; root = root->left) {
        stack_push(&obj->stack, root);
    }
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return !stack_isempty(&(obj->stack));
}

void bSTIteratorFree(BSTIterator* obj) {
    stack_free(&obj->stack);
    free(obj);
}

int
main(void) {
    int nums[] = {10, 5, 15, 7, 18, 3, 12, 1, 11, 19, 4, 2};
    struct TreeNode * root = NULL;
    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n");

    BSTIterator* it = bSTIteratorCreate(root);
    while (bSTIteratorHasNext(it)) {
        printf("[%d]\n", bSTIteratorNext(it));
    }
    bSTIteratorFree(it);

    return 0;
}
