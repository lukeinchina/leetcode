#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"
/*
struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

struct TreeNode *
list_to_bst(struct ListNode *head, int count) {
    int i = 0;
    struct ListNode *p    = head;
    struct TreeNode *root = NULL;
    if (count <= 0) {
        return NULL;
    }
    for (i = 0; i < count/2; i++) {
        p = p->next;
    }
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val   = p->val;
    root->left  = list_to_bst(head, count/2);
    root->right = list_to_bst(p->next, (count+1)/2 - 1);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int count = 0;
    struct ListNode *p = head;
    for (; NULL != p; p = p->next) {
        count++;
    }
    return list_to_bst(head, count);
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
    int i;
    int nums[] = {-10,-3,0,5,9, 20};
    struct ListNode *head = NULL;
    struct TreeNode *root = NULL;
    for (i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        head = linked_list_insert_tail(head, nums[i]);
    }
    linked_list_print(head);
    root = sortedListToBST(head);
    print_tree(root);
    printf("\n");
    return 0;
}
