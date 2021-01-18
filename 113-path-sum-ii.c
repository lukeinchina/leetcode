#include <stdio.h>
#include <stdlib.h>
#include "common/base_type.h"
#include "common/array.h"

int max_path(struct TreeNode *root) {
    int l, r;
    if (NULL == root) {
        return 0;
    }
    l = max_path(root->left);
    r = max_path(root->right);
    return (l > r ? l : r) + 1;
}

void print_array(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", array[i], i+1 != size ? '\t' : '\n');
    }
}

void path_sum(struct TreeNode *root, int sum, int *stack, int top, 
        struct ArrayHead *head) {
    if (NULL == root) {
        return ;
    }
    sum -= root->val;
    stack[top] = root->val;
    if (NULL == root->left && NULL == root->right) {
        if (0 == sum) {
            array_append(head, stack, top+1);
        }
        return ;
    }
    path_sum(root->left, sum, stack, top+1, head);
    path_sum(root->right, sum, stack, top+1, head);
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int depth = max_path(root);
    int *stack = (int *)malloc(sizeof(int) * depth);

    struct ArrayHead head = {NULL, NULL, 0, 0};
    path_sum(root, sum, stack, 0, &head);
    *returnSize = head.size;
    *returnColumnSizes = head.cols;
    return head.array;
}

int
main(int argc, char *argv[]) {
    int **pp = NULL;
    int i, size = 0;
    int *cols   = NULL;
    struct TreeNode *root = NULL;
    int nums[] = {7, 11, 13, 8, 4, 5, 2, 1};
    if (argc < 2) {
        printf("suage:%s sum\n", argv[0]);
        return 0;
    }
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    pp = pathSum(root, atoi(argv[1]), &size, &cols);
    for (i = 0; i < size; i++) {
        print_array(pp[i], cols[i]);
    }
    return 0;
}
