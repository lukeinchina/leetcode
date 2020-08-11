#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int              val;
    struct ListNode *next;
};

struct ListNode *merge_sorted_list(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode head = {-1, NULL};
    struct ListNode *p = &head;
    while (NULL != l1 && NULL != l2) {
        if (l1->val < l2->val) {
            p->next  = l1;
            l1 = l1->next;
        } else {
            p->next  = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = (NULL != l1 ? l1 : l2);
    return head.next;
}

void print_list_node(const struct ListNode *head) {
    if (NULL != head) {
        printf("%d ", head->val);
        print_list_node(head->next);
    }
}

int
main(void) {
    int i;
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 3, 4, 5, 6};
    struct ListNode head = {-1, NULL};
    struct ListNode *L1  = NULL;
    struct ListNode *L2  = NULL;
    struct ListNode *p   = NULL;
    for (i = sizeof(array1)/sizeof(array1[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array1[i];
        p->next   = head.next;
        head.next = p;
    }
    L1 = head.next;
    print_list_node(L1);
    printf("\n");
    head.next = NULL;
    for (i = sizeof(array2)/sizeof(array2[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array2[i];
        p->next   = head.next;
        head.next = p;
    }
    L2 = head.next;
    p = merge_sorted_list(L1, L2);
    print_list_node(p);
    printf("\n");
}
