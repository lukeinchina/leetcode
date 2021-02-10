#include <stdio.h>
#include "common/base_type.h"

struct ListNode *
reverse(struct ListNode *head) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *p = head;
    while (NULL != p) {
        head = p->next;
        p->next = dummy.next;
        dummy.next = p;
        p = head;
    }
    return dummy.next;
}

struct ListNode *
cross_list(struct ListNode *h1, struct ListNode *h2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *p = &dummy;
    while (NULL != h1 && NULL != h2) {
        p->next = h1;
        h1      = h1->next;
        p       = p->next;

        p->next = h2;
        h2      = h2->next;
        p       = p->next;
    }
    p->next = (NULL == h1 ? h2 : h1);
    return dummy.next;
}

void reorderList(struct ListNode* head){
    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;
    struct ListNode *r;

    while (NULL != fast && NULL != fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    r = slow->next;
    slow->next = NULL;
    r = reverse(r);
    cross_list(dummy.next, r);
}

int
main(void) {
    int nums[] = {1, 2};
    struct ListNode *head = linked_list_create(nums, sizeof(nums) / sizeof(nums[0]));
    linked_list_print(head);
    reorderList(head);
    linked_list_print(head);
    return 0;
}
