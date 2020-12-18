#include <stdio.h>
#include <stdlib.h>

#include "common/base_type.h"


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int i;
    struct ListNode dummy = {0, head};
    struct ListNode *rear = &dummy;
    struct ListNode *tail;
    struct ListNode *p, *q;

    for (i = 1; i < m; i++) {
        rear = rear->next;
    }
    tail  = rear->next;
    p     = tail->next;
    tail->next = NULL;
    for (; i < n; i++) {
        q = p;
        p = p->next;
        /* 插入到第m位，实现反转效果。*/
        q->next    = rear->next;
        rear->next = q;
    }
    /* n个节点后面保持不动 */
    tail->next = p;
    return dummy.next;
}

int
main(int argc, char *argv[]) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = linked_list_create(nums, sizeof(nums)/ sizeof(nums[0]));
    if (argc < 3) {
        printf("usage:%s m  n\n", argv[0]);
        return -1;
    }
    linked_list_print(head);
    head = reverseBetween(head, atoi(argv[1]), atoi(argv[2]));
    linked_list_print(head);
    return 0;
}
