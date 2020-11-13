#include "vector.h"

int vector_init(struct Vector *v) {
    v->capacity = 8;
    v->size     = 0;
    v->arr = (int *)malloc(sizeof(int) * v->capacity);
    return 0;
}

int vector_destroy(struct Vector *v) {
    if (NULL != v->arr) {
        free(v->arr);
    }
    v->arr      = NULL;
    v->size     = 0;
    v->capacity = 0;
    return 0;
}

int vector_append(struct Vector *v, int val) {
    if (v->capacity == 0) {
        vector_init(v);
    } else if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int *)realloc(v->arr, sizeof(int) * v->capacity);
    }
    v->arr[v->size++] = val;
    return 0;
}
