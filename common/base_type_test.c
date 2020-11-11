#include <stdio.h>
#include <assert.h>
#include "base_type.h"

void 
test_linked_list(void) {
    int array[] = {1,2,3,4,5,6,7,8,9,0};
    int size    = sizeof(array) / sizeof(array[0]);
    int i;
    struct ListNode *l1 = linked_list_create(array, size);
    struct ListNode *l2, *p, *q;
    q = p = l2 = NULL;
    for (i = size-1; i >= 0; i--) {
        l2 = linked_list_insert_head(l2, array[i]);
    }
    for (i = 0; i < size; i++) {
        assert(NULL != l1);
        assert(NULL != l2);
        assert(array[i] == l1->val && array[i] == l2->val);
        l1 = l1->next;
        l2 = l2->next;
    }

    /* tail insert test */
    l1 = linked_list_insert_tail(l1, 10);
    for (p = l1; NULL != p->next; p = p->next) {
    }
    assert(p->val == 10);

    l1 = linked_list_destroy(l1);
    l1 = linked_list_destroy(l2);
    assert(NULL == l1);
    assert(NULL == l2);
    printf("\033[40;32;1mlinkedlist's testing pass \033[0m\n");
}

void test_binary_tree(void) {
    int array[] = {10, 5, 15, 3, 9, 20, 18, 6, 12, 16, 7, 8};
    struct TreeNode *root = NULL;
    struct TreeNode *p = NULL;
    int i, min, max;
    min = max = array[0];
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        root = tree_insert(root, array[i]);
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    tree_print_in_order(root);
    printf("\n");
    p = root;
    assert(p->val == array[0]);
    while (NULL != p->left) {
        p = p->left;
    }
    assert(p->val == min);

    for (i = 0; i+1 < sizeof(array) / sizeof(array[0]); i++) {
        root = tree_delete(root, array[i]);
    }
    tree_print_in_order(root);
    printf("\n");
    assert(root->val == array[i]);
    printf("\033[40;32;1mbinary_tree's testing pass \033[0m\n");
}

int
main(void) {
    test_linked_list();
    test_binary_tree();
    return 0;
}
