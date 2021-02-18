#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "common/base_type.h"

struct ListNode *
merge_sorted_list(struct ListNode *h1, struct ListNode *h2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *p = &dummy;
    while (NULL != h1 && NULL != h2) {
        if (h1->val < h2->val) {
            p->next = h1;
            h1      = h1->next;
        } else {
            p->next = h2;
            h2      = h2->next;
        }
        p = p->next;
    }
    p->next = (NULL == h1 ? h2 : h1);
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *fast, *slow;
    struct ListNode dummy = {0, head};
    if (NULL == head || NULL == head->next) {
        return head;
    }
    fast = slow = &dummy;
    while (NULL != fast && NULL != fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = sortList(slow->next); /* reuse var */
    slow->next = NULL;
    slow  = sortList(head);
    head  = merge_sorted_list(slow, fast);
    return head;
}

int
main(void) {
    int nums[] = {5, 8, 1, 3, 9, 0, 2};
    struct ListNode *head = linked_list_create(nums, sizeof(nums) / sizeof(nums[0]));
    linked_list_print(head);
    head = sortList(head);
    linked_list_print(head);
    return 0;
}
