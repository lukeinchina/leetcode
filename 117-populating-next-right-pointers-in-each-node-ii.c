#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
    struct Node *prev, *parent = root;
    struct Node dummy = {0, NULL, NULL, NULL};
    while (NULL != parent) {
        dummy.next = NULL;
        for (prev = &dummy; NULL != parent; parent = parent->next) {
            if (NULL != parent->left)  {
                prev->next = parent->left;
                prev = prev->next;
            } 
            if (NULL != parent->right) {
                prev->next = parent->right;
                prev = prev->next;
            }
        }
        /* next level */
        parent = dummy.next;
    }
    return root;
}

struct Node *
insert(struct Node *root, int val) {
    if (NULL == root) {
        root = (struct Node *)calloc(1, sizeof(struct Node));
        root->val = val;
    } else if (root->val > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void print_tree(struct Node *root) {
    if (NULL == root) {
        return;
    }
    print_tree(root->left);
    printf("%d\t", root->val);
    print_tree(root->right);
}

struct Node *first_child(struct Node *root) {
    while (NULL != root) {
        if (NULL == root->left && NULL == root->right) {
            root = root->next;
        } else {
            return (root->left ? root->left : root->right);
        }
    }
    return root;
}
void print_level(struct Node *root) {
    struct Node *next;
    struct Node *first;
    for (; NULL != root; root = first_child(first)) {
        first = root;
        for (next = root; NULL != next; next = next->next) {
            printf("%d\t", next->val);
        }
        printf("\n");
    }
}

/*            6
 *          /   \
 *         4     9
 *       /        \
 *      2          10
 *     / \
 *    1   3
 *   /
 *  0
 */

int
main(void) {
    int i;
//    int nums[] = {6, 9, 10, 4, 2, 3, 1, 0};
    int nums[] = {6, 9, 10, 4, 8};
    struct Node *root = NULL;
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = insert(root, nums[i]);
    }
    print_tree(root);
    printf("\n");
    root = connect(root);
    print_level(root);
    printf("\n");
    return 0;
}
