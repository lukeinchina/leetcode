#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (NULL == p && NULL == q) {
        return true;
    }else if (NULL != p && NULL != q && q->val == p->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}

int
main(int argc, char *argv[]) {
    int nums[] = {5, 3, 7, 2, 6};
    return 0;
}
