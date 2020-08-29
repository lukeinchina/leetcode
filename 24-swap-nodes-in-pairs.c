#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int              val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode dummy = {-1, head};
    struct ListNode *p = &dummy;
    struct ListNode *q, *t;
    while (NULL != p->next) {
        q = p->next;
        if (NULL == q->next) {
            break;
        }
        t = q->next;

        p->next = q->next;
        q->next = t->next;
        t->next = q;

        /* for next swap */
        p = q;
    }
    return dummy.next;
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
    int array1[] = {1};
    struct ListNode head = {-1, NULL};
    struct ListNode *p   = NULL;
    for (i = sizeof(array1)/sizeof(array1[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array1[i];
        p->next   = head.next;
        head.next = p;
    }
    p = head.next;
    print_list_node(p);
    printf("\n");
    p = swapPairs(p);
    print_list_node(p);
    printf("\n");
    return 0;
}
