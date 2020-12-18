#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode less    = {0, NULL};
    struct ListNode greater = {0, NULL};
    struct ListNode *tail   = &less;
    struct ListNode *rear   = &greater;
    struct ListNode *p;
    while (NULL != head) {
        p    = head;
        head = head->next;
        p->next = NULL;

        if (p->val < x) {
            tail->next = p;
            tail = tail->next;
        } else {
            rear->next = p;
            rear = rear->next;
        }
    }
    tail->next = greater.next;
    return less.next;
}

int
main(void) {
    int nums[] = {5, 5, 2, 2, 3, 3, 1, 1, 4, 8, 0};
    struct ListNode *head = linked_list_create(nums, sizeof(nums)/ sizeof(nums[0]));
    linked_list_print(head);
    head = partition(head, 3);
    linked_list_print(head);
    return 0;
}
