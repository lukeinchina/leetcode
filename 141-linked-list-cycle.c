#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (NULL != fast) {
        fast = fast->next;
        slow = slow->next;
        if (NULL == fast) {
            return false;
        }
        fast = fast->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}
