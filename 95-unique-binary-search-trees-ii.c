#include <stdio.h>
#include <stdlib.h>
#include "common/base_type.h"

struct TreeNode **all_trees(int start, int end, int *count, const int *dp) {
    int i, l, r, lcount, rcount, index = 0;
    struct TreeNode **trees;
    struct TreeNode *root;
    struct TreeNode **ltrees;
    struct TreeNode **rtrees;

    *count   = dp[end+1 - start];
    trees    = (struct TreeNode **)calloc(*count, sizeof(struct TreeNode *));

    /* make faster. can be deleted */
    if (start == end) {
        trees[0]      = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
        trees[0]->val = start;
        return trees;
    }
    /* val = idx 为root的树 */
    for (i = start; i <= end; i++) {
        /* 左子树  */
        ltrees = all_trees(start, i-1, &lcount, dp);
        rtrees = all_trees(i+1, end, &rcount, dp);
        for (l = 0; l < lcount; l++) {
            /* 右子树  */
            for (r = 0; r < rcount; r++) {
                root        = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                root->val   = i;
                root->left  = ltrees[l];
                root->right = rtrees[r];
                trees[index++] = root;
            }
        }
    }
    return trees;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    int i, j, dp[64];
    dp[0] = dp[1] = 1; dp[2] = 2;
    for (i = 2; i <= n; i++) {
        dp[i] = 0;
        for (j = 1; j <= i; j++)  {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    if (0 == n) {
        *returnSize = 0;
        return NULL;
    }
    return all_trees(1, n, returnSize, dp);
}

void print_tree(const struct TreeNode *root) {
    if (NULL == root) {
        return ;
    }
    printf("%d\t", root->val);
    print_tree(root->left);
    print_tree(root->right);
}

int
main(int argc, char *argv[]) {
    int i, total;
    struct TreeNode **trees = NULL;
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    trees = generateTrees(atoi(argv[1]), &total);
    printf("%d\n", total);
    printf("-----------\n");
    for (i = 0; i < total; i++) {
        print_tree(trees[i]);
        printf("\n--------\n");
    }
    return 0;
}

