#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* 
addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int flag = 0;
    struct ListNode head = {0, NULL};
    struct ListNode *p   = &head;
    struct ListNode *q   = NULL;
    while (NULL != l1 && NULL != l2) {
        p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        p       = p->next;

        p->val  = (flag + l1->val + l2->val) % 10;
        flag    = (flag + l1->val + l2->val) / 10;

        l1 = l1->next;
        l2 = l2->next;
    }
    q = (NULL == l1 ? l2 : l1);
    while (NULL != q) {
        p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        p       = p->next;

        p->val  = (flag + q->val) % 10;
        flag    = (flag + q->val) / 10;

        q = q->next;
    }
    if (0 != flag) {
        p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        p       = p->next;
        p->val  = flag;
    }
    return head.next;
}
