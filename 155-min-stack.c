#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int *min_stack;
    int top;
    int min_top;
    int size;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s  = (MinStack *) malloc(sizeof(MinStack));
    s->size      = 8;
    s->top       = 0;
    s->min_top   = 0;
    s->stack     = (int *)malloc(sizeof(int) * s->size);
    s->min_stack = (int *)malloc(sizeof(int) * s->size);

    return s;
}

void minStackExpand(MinStack *obj) {
    obj->size      *= 2;
    obj->stack     = (int *)realloc(obj->stack, sizeof(int) * obj->size);
    obj->min_stack = (int *)realloc(obj->min_stack, sizeof(int) * obj->size);
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == obj->size) {
        minStackExpand(obj);
    }
    obj->stack[obj->top++] = x;

    if (0 == obj->min_top || obj->min_stack[obj->min_top-1] >= x) {
        obj->min_stack[obj->min_top++] = x;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == 0) {
        return;
    }
    obj->top -= 1;
    if (obj->min_stack[obj->min_top-1] == obj->stack[obj->top]) {
        obj->min_top -= 1;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top-1];
}

int minStackGetMin(MinStack* obj) {

    return obj->min_stack[obj->min_top-1];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int
main(void) {
    int a , b;
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    a = minStackTop(obj);
    b = minStackGetMin(obj);
    printf("top:%d, min:%d\n", a, b);
    minStackPop(obj);
    a = minStackTop(obj);
    b = minStackGetMin(obj);
    printf("top:%d, min:%d\n", a, b);

    minStackFree(obj);
    return 0;
}
