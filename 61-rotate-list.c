#include <stdio.h>
#include <stdlib.h>
#include "common/base_type.h"
int list_length(const struct ListNode *head) {
    int count = 0;
    while (NULL != head) {
        count += 1;
        head = head->next;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    int i;
    struct ListNode *tail, *p;
    struct ListNode dummy = {0, head};
    int count = list_length(head);
    if (count <= 1 || (k % count == 0)) {
        return head;
    }
    k %= count;
    tail = p = &dummy;
    for (i = 0; i < k && NULL != p->next; i++) {
        p = p->next;
    }
    for (; NULL != p->next; p = p->next) {
        tail = tail->next;
    }
    
    head       = tail->next;
    tail->next = NULL;
    p->next    = dummy.next;
    dummy.next = head;

    return dummy.next;
}

int
main(int argc, char *argv[]) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = linked_list_create(nums, sizeof(nums)/sizeof(nums[0]));
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    linked_list_print(head);
    head = rotateRight(head, atoi(argv[1]));
    linked_list_print(head);
    return 0;
}
