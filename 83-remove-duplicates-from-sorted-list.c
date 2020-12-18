#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *curr = head;
    struct ListNode *p = NULL;
    while (NULL != curr) {
        if (NULL != curr->next && curr->next->val == curr->val) {
            p = curr->next;
            curr->next = p->next;
            free(p);
        } else {
            curr = curr->next;
        }
    }
    return head;
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
