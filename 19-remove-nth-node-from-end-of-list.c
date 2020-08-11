#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int              val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode prehead = {-1, head};
    struct ListNode *p = head;
    struct ListNode *q = &prehead;
    int i = 0;
    for (i = 0; i < n; i++) {
        p = p->next;
    }
    for (; NULL != p; p = p->next) {
        q = q->next;
    }
    /* free */
    q->next = q->next->next;
    return prehead.next;
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
    int array[] = {1, 2, 3, 4, 5};
    struct ListNode head = {-1, NULL};
    struct ListNode *p   = NULL;
    for (i = sizeof(array)/sizeof(array[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array[i];
        p->next   = head.next;
        head.next = p;
    }
    print_list_node(head.next);
    printf("\n");
    p = removeNthFromEnd(head.next, 5);
    print_list_node(p);
    printf("\n");
}
