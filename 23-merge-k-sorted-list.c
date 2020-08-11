#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int              val;
    struct ListNode *next;
};


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i, min;
    struct ListNode head = {-1, NULL};
    struct ListNode *p   = &head;
    struct ListNode *q   = NULL;
    while (1) {
        for (i = 0; i < listsSize && NULL == lists[i]; i++) {
        }
        if (i == listsSize) {
            break;
        }
        min = i;
        q = NULL;
        for (i += 1; i < listsSize; i++) {
            if (NULL == lists[i]) {
                continue;
            }
            q = lists[i];
            if (lists[i]->val < lists[min]->val) {
                min = i;
            }
        }

        if (NULL == q) {
            p->next = lists[min];
            break;
        } else {
            p->next    = lists[min];
            lists[min] = lists[min]->next;
            p = p->next;
        }
    }
    return head.next;
}

struct ListNode *merge_sorted_list(struct ListNode **list, int size) {
    return mergeKLists(list, size);
}

void print_list_node(const struct ListNode *head) {
    if (NULL != head) {
        printf("%d ", head->val);
        print_list_node(head->next);
    }
}

int
main(void) {
    int i;
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 3, 4, 5, 6};
    struct ListNode head = {-1, NULL};
    struct ListNode *L1  = NULL;
    struct ListNode *L2  = NULL;
    struct ListNode *p   = NULL;
    struct ListNode *list[3];
    for (i = sizeof(array1)/sizeof(array1[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array1[i];
        p->next   = head.next;
        head.next = p;
    }
    L1 = head.next;
    print_list_node(L1);
    printf("\n");
    head.next = NULL;
    for (i = sizeof(array2)/sizeof(array2[0])-1; i >= 0; i--) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val    = array2[i];
        p->next   = head.next;
        head.next = p;
    }
    L2 = head.next;
    list[0] = L1;
    list[1] = L2;
    list[2] = NULL;
    p = merge_sorted_list(list, 3);
    print_list_node(p);
    printf("\n");
}
