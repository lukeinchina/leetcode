#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *get_last(struct ListNode *head) {
    while (NULL != head->next) {
        head = head->next;
    }
    return head;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p;
    struct ListNode *fast, *slow;
    if (NULL == headA || NULL == headB || headA == headB) {
        return headA == headB ? headA : NULL;
    }

    /* mark circle */
    p = get_last(headA);
    p->next = headA;

    fast = slow = headB;
    while (NULL != fast && NULL != fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }

    /* 无交集 */
    if (NULL == fast || NULL == fast->next) {
        p = p->next;
        return NULL;
    }
    fast = headB;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    p->next = NULL;
    return fast;
}


