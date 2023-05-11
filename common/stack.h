#ifndef LEETCODE_COMMON_STACK_H_
#define LEETCODE_COMMON_STACK_H_

typedef void *ElemType; 

typedef struct {
    ElemType *stack;
    int top; 
    int size;
}Stack;

void stack_init(Stack *s);
void stack_free(Stack *s);
void stack_push(Stack *s, ElemType val);
int  stack_isempty(const Stack *s); /* 栈空返回!0，其他0 */
ElemType stack_pop(Stack *s);
ElemType stack_top(const Stack *s);

#endif
