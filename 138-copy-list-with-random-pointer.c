#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    struct Node *p = head;
    struct Node *q = p;
    struct Node dummy = {-1, NULL, NULL};

    /* A - A' -> B -> B' -> C -> C' */
    while (NULL != p) {
        q       = (struct Node *)calloc(1, sizeof(struct Node));
        q->val  = p->val;
        q->next = p->next;
        p->next = q;
        p       = q->next;
    }

    /* set random pointer */
    p = head;
    while (NULL != p) {
        if (NULL != p->random) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }

    /* A - A' -> B -> B' to  A->B, A'->B' */
    q = &dummy;
    p = head;
    while (NULL != p) {
        q->next = p->next;
        q = q->next;

        p->next = p->next->next;
        p = p->next;
    }
    return dummy.next;
}

struct Node *
create_list(const int nums[], int size) {
    int i;
    struct Node head = {-1, NULL, NULL};
    struct Node *p = &head;
    for (i = 0; i < size; i++) {
        p->next = (struct Node *)calloc(1, sizeof(struct Node));
        p->next->val = nums[i];
        p = p->next;
    }
    return head.next;
}

void print_list(struct Node *head) {
    if (NULL == head) {
        return ;
    }
    printf("%d%c", head->val, 
            (NULL == head->next ? '\n' : '-'));
    print_list(head->next);
}

void print_random_list(struct Node *head) {
    if (NULL == head) {
        return ;
    }
    printf("[%d:%d]%c", head->val, 
            (NULL == head->random ? 0 : head->random->val),
            (NULL == head->next ? '\n' : '-'));
    print_random_list(head->next);
}

int
main(void) {
    int nums[] = {7, 13, 11, 10, 1};
    struct Node *head = create_list(nums, sizeof(nums) / sizeof(nums[0]));
    struct Node *p, *q;
    print_list(head);

    head->random = NULL; /* 1 --> NULL */
    head->next->random = head;       /* 2 --> 1 */
    p = head->next->next; /* 3 */
    p->random = p->next->next;  /* 3 --> 5 */ 
    p = p->next;          /* 4 */
    p->random = head->next->next;     /* 4 --> 1 */
    p->next->random = head; /* 5 --> 2 */

    print_random_list(head);

    q = copyRandomList(head);
    print_random_list(q);
    return 0;
}
