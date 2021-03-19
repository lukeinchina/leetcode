#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *q = NULL;
    struct ListNode *p;
    while (NULL != head) {
        p    = head;
        head = head->next;

        p->next = q;
        q       = p;
    }
    return q;
}
