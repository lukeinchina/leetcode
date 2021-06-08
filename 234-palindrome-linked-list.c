#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *
reverse_list(struct ListNode *head) {
    struct ListNode dummy = {-1, NULL};
    struct ListNode *p, *q;
    p = &dummy;
    while (NULL != head) {
        q    = head;
        head = head->next;
        q->next = p->next;
        p->next = q;
    }
    return dummy.next;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode dummy = {-1, head};
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;
    struct ListNode *p, *q;
    bool flag = true;

    if (NULL == head || NULL == head->next) {
        return true;
    }

    /* 找到中间节点 */
    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    p = head;
    q = reverse_list(slow->next);
    slow->next = NULL;
    fast = q; /* 记录 后半段，恢复时使用 */

    while (NULL != p && NULL != q) {
        if (p->val != q->val) {
            flag = false;
            break;
        }
        p = p->next;
        q = q->next;
    }
    slow->next = reverse_list(fast);
    return flag;
}
