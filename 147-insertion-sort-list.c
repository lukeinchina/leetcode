#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "common/base_type.h"

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode dummy = {INT_MIN, NULL};
    struct ListNode *p;
    struct ListNode *q;
    while (NULL != head) {
        q    = head;
        head = head->next;
        p    = &dummy;
        while (NULL != p->next && q->val >= p->next->val) {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
    return dummy.next;
}

int
main(void) {
    // int nums[] = {5, 8, 1, 3, 9, 0, 2};
    int nums[] = {2};
    struct ListNode *head = linked_list_create(nums, sizeof(nums) / sizeof(nums[0]));
    linked_list_print(head);
    head = insertionSortList(head);
    linked_list_print(head);
    return 0;
}
