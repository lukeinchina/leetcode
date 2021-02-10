#include <stdlib.h>
#include <stdio.h>
#include "common/base_type.h"

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (NULL != fast && NULL != fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            // printf("meeting:%d\n", slow->val);
            break;
        }
    }
    if (NULL == fast || NULL == fast->next) {
        return NULL;
    }
    fast = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int
main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct ListNode *head = linked_list_create(nums, sizeof(nums) / sizeof(nums[0]));
    struct ListNode *p, *q;
    linked_list_print(head);
    p = head;
    while (NULL != p->next) {
        p = p->next;
    }
    // p->next = head->next->next;
    q = detectCycle(head);
    if (NULL != q) {
        printf("pos:%d\n", q->val);
    } else {
        printf("pos:null\n");
    }
    return 0;
}
