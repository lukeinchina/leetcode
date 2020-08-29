#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int              val;
    struct ListNode *next;
};

struct ListNode *reverse_list(struct ListNode *head) {
    struct ListNode *newhead = NULL;
    struct ListNode *left = NULL;
    while (NULL != head) {
        left = head->next;
        head->next = newhead;
        newhead = head;
        head = left;
    }
    return newhead;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int i;
    struct ListNode *p, *pre;
    struct ListNode *newhead = NULL;
    struct ListNode *newtail = NULL;
    struct ListNode *ktail   = NULL;
    struct ListNode *khead   = head;
    pre = p = head;
    while (1) {
        khead = p;
        for (i = 0; i < k && NULL != p; i++) {
            pre = p;
            p = p->next;
        }
        /* 不足一组，结束 */
        if (i < k) {
            if (NULL == newhead) {
                return head;
            }
            newtail->next = khead;
            return newhead;
        }
        /* 本group截断, 翻转 */
        pre->next = NULL;
        ktail = khead;
        khead = reverse_list(khead);

        if (NULL == newhead) {
            newhead = khead;
        }
        if (NULL == newtail) {
            newtail = ktail;
        } else {
            newtail->next = khead;
            newtail = ktail;
        }
    }
    return newhead;
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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct ListNode head = {-1, NULL};
    struct ListNode *p   = NULL;
    for (i = sizeof(array)/sizeof(array[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array[i];
        p->next   = head.next;
        head.next = p;
    }
    p = head.next;
    print_list_node(p);
    printf("\n");
    p = reverseKGroup(p, 1);
    print_list_node(p);
    printf("\n");
    return 0;
}
