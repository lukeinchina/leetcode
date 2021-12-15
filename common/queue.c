#include <stdlib.h>
#include "queue.h"

struct QueueNode {
    ElemType         val;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode dummy;
    struct QueueNode *head;
    struct QueueNode *tail;
    int    length;
};

struct Queue * create_queue(void)  {
    struct Queue *q = (struct Queue *)calloc(1, sizeof(struct Queue));
    q->head  = q->tail = &(q->dummy);
    return q;
}

void * free_queue(struct Queue *q) {
    struct QueueNode *p = q->head->next;
    while (NULL != p) {
        q->head->next = p->next;
        free(p);
        p = q->head->next;
    }
    free(q);
    return NULL;
}

int 
queue_push(struct Queue *q, ElemType val) {
    struct QueueNode *p = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    p->val        = val;
    p->next       = NULL;
    q->tail->next = p;
    q->tail       = q->tail->next;
    q->length     += 1;
    return 0;
}

int queue_pop(struct Queue *q, ElemType *val) {
    struct QueueNode *p;
    if (q->tail == q->head) {
        return -1;
    } else if (q->tail == q->head->next) {
        /* 剩余一个元素 */
        q->tail = q->head;
    }

    p             = q->head->next;
    *val          = p->val;
    q->head->next = p->next;
    q->length    -= 1;
    free(p);

    return 0;
}

int queue_tail(struct Queue *q, ElemType *val) {
    if (q->head == q->tail) {
        return -1;
    }
    *val = q->tail->val;
    return 0;
}

int queue_head(struct Queue *q, ElemType *val) {
    if (q->head == q->tail) {
        return -1;
    }
    *val = q->head->next->val;
    return 0;
}

int 
queue_empty(const struct Queue *q) {
    return q->tail == q->head ? 1 : 0;
}

int 
queue_length(const struct Queue *q) {
    return q->length;
}
