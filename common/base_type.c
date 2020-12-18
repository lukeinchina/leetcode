#include <stdlib.h>
#include <stdio.h>
#include "base_type.h"

struct ListNode *
linked_list_create(int *array, int size) {
    struct ListNode head = {0, NULL};
    struct ListNode *p   = &head;
    int i;
    for (i = 0; i < size; i++) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p       = p->next;
        p->val  = array[i];
        p->next = NULL;
    }
    return head.next;
}

struct ListNode *
linked_list_destroy(struct ListNode *head) {
    struct ListNode *p = head;
    while (NULL != head) {
        head = head->next;
        free(p);
        p = head;
    }
    return NULL;
}

struct ListNode *
linked_list_insert_head(struct ListNode *head, int val) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val  = val;
    p->next = head;
    return p;
}

struct ListNode *
linked_list_insert_tail(struct ListNode *head, int val) {
    struct ListNode dummy = {0, head};
    struct ListNode *p    = &dummy;
    while (NULL != p->next) {
        p = p->next;
    }
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p       = p->next;
    p->val  = val;
    return dummy.next;
}

/* insert in order */
struct ListNode *
linked_list_insert(struct ListNode *head, int val) {
    return linked_list_insert_head(head, val);
}

void linked_list_print(const struct ListNode *head) {
    for (; NULL != head; head = head->next) {
        printf("%d%c", head->val, (NULL == head->next) ? '\n' : ' ');
    }
    return;
}

/*----------------------binary tree -------------------------*/
struct TreeNode *
tree_insert(struct TreeNode *root, int val) {
    if (NULL == root) {
        root = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
        root->val = val;
    }else if (root->val > val) {
        root->left = tree_insert(root->left, val);
    } else {
        root->right = tree_insert(root->right, val);
    }
    return root;
}

struct TreeNode *
tree_delete(struct TreeNode *root, int val) {
    if (NULL == root) {
        return NULL;
    }else if (root->val > val) {
        root->left = tree_delete(root->left, val);
    } else if (root->val < val){
        root->right = tree_delete(root->right, val);
    } else {
        struct TreeNode *p = root;
        if (NULL == root->left) {
            root = root->right;
            free(p);
        } else if (NULL == root->right) {
            root = root->left;
            free(p);
        } else {
            /* 右边最小值替换 */
            root = root->right;
            while (NULL != root->left) {
                root = root->left;
            }
            p->val = root->val;

            p->right = tree_delete(p->right, root->val);
            root = p;
        }
    }
    return root;
}

void tree_print_in_order(struct TreeNode *root) {
    if (NULL == root) {
        return;
    }
    tree_print_in_order(root->left);
    printf("%d\t", root->val);
    tree_print_in_order(root->right);
    return;
}

struct TreeNode *tree_destroy(struct TreeNode *root) {
    if (NULL != root) {
        root->left = tree_destroy(root->left);
        root->right = tree_destroy(root->right);
        free(root);
    }
    return NULL;
}
