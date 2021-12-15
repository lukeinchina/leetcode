#ifndef LEET_CODE_COMMON_QUEUE_H_
#define LEET_CODE_COMMON_QUEUE_H_

typedef int ElemType;
struct Queue;

struct Queue* create_queue(void);
void * free_queue(struct Queue *q);
int queue_push(struct Queue *q, ElemType val);
int queue_pop(struct Queue *q, ElemType *val);
int queue_tail(struct Queue *q, ElemType *val);
int queue_head(struct Queue *q, ElemType *val);
int queue_empty(const struct Queue *q);
int queue_length(const struct Queue *q);

#endif
