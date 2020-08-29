#include <stdlib.h>
#include <stdio.h>
#include "base_type.h"

struct ListNode *
linked_list_create(int *array, int size) {
    struct ListNode head = {0, NULL};
    struct ListNode *p   = &head;
    int i;
    for (i = 0; i < size; i++) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p       = p->next;
        p->val  = array[i];
        p->next = NULL;
    }
    return head.next;
}

struct ListNode *
linked_list_destroy(struct ListNode *head) {
    struct ListNode *p = head;
    while (NULL != head) {
        head = head->next;
        free(p);
        p = head;
    }
    return NULL;
}

struct ListNode *
linked_list_insert_head(struct ListNode *head, int val) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val  = val;
    p->next = head;
    return p;
}

struct ListNode *
linked_list_insert_tail(struct ListNode *head, int val) {
    struct ListNode dummy = {0, head};
    struct ListNode *p    = &dummy;
    while (NULL != p->next) {
        p = p->next;
    }
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p       = p->next;
    p->val  = val;
    return dummy.next;
}

/* insert in order */
struct ListNode *
linked_list_insert(struct ListNode *head, int val) {
    return head;
}

void linked_list_print(const struct ListNode *head) {
    for (; NULL != head; head = head->next) {
        printf("%d%c", head->val, (NULL == head->next) ? '\n' : ' ');
    }
    return;
}
