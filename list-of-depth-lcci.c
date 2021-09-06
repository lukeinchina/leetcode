#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *typename;
struct Vector {
    typename *arr;
    int size;
    int capacity;
};

int vector_init(struct Vector *v) {
    v->capacity = 8;
    v->size     = 0;
    v->arr = (typename *)malloc(sizeof(typename) * v->capacity);
    return 0;
}

int vector_append(struct Vector *v, typename val) {
    if (v->capacity == 0) {
        vector_init(v);
    } else if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (typename *)realloc(v->arr, sizeof(typename) * v->capacity);
    }
    v->arr[v->size++] = val;
    return 0;
}

struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
    struct ListNode dummy;
}
