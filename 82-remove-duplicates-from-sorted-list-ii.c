#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"

struct ListNode* deleteDuplicates(struct ListNode* head){
    int    val;
    struct ListNode dummy = {0, head};
    struct ListNode *rear = &dummy;
    struct ListNode *p;
    while (NULL != head && NULL != head->next) {
        val = head->val;
        if (val != head->next->val) {
            head = head->next;
            rear = rear->next;
            continue;
        }
        while (NULL != head && head->val == val) {
            p = head;
            head = head->next;
            free(p);
        }
        rear->next = head;
    }
    return dummy.next;
}

int
main(void) {
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    struct ListNode *head = linked_list_create(nums, sizeof(nums)/ sizeof(nums[0]));
    linked_list_print(head);
    head = deleteDuplicates(head);
    linked_list_print(head);
    return 0;
}
