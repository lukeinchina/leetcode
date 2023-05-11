#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void stack_init(Stack *s) {
    s->top  = 0;
    s->size = 8;
    s->stack = (ElemType *)malloc(sizeof(ElemType) * s->size);
}

void stack_free(Stack *s) {
    free(s->stack);
    s->stack = NULL;
    s->top   = 0; 
    s->size  = 0;
}

void stack_push(Stack *s, ElemType val) {
    if (s->top == s->size) {
        s->size *= 2;
        s->stack = (ElemType *)realloc(s->stack, sizeof(ElemType) * s->size);
    }
    s->stack[s->top++] = val;
}

/* 栈空返回!0，其他0 */
int stack_isempty(const Stack *s) {
    return (s->top == 0);
}

ElemType stack_pop(Stack *s) {
    assert(s->top > 0);
    return s->stack[--s->top];
}

ElemType stack_top(const Stack *s) {
    assert(s->top > 0);
    return s->stack[s->top - 1];
}
