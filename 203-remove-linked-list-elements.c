#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode dummy = {-1, head};
    struct ListNode *p = &dummy;
    struct ListNode *q = NULL;
    while (p->next != NULL) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return dummy.next;
}
