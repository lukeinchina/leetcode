#ifndef LEETCODE_COMMON_VECTOR_H_
#define LEETCODE_COMMON_VECTOR_H_

#include <stdlib.h>

struct Vector {
    int *arr;
    int size; 
    int capacity;
};

int vector_init(struct Vector *v);
int vector_destroy(struct Vector *v);
int vector_append(struct Vector *v, int val);
#endif
