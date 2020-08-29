#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "array.h"

int 
array_init(struct ArrayHead *head) {
    head->size     = 0;
    head->capacity = 8;
    head->array = (int **)malloc(sizeof(int*) * head->capacity);
    head->cols  = (int *)calloc(head->capacity, sizeof(int));
    return 0;
}

int 
array_append(struct ArrayHead *head, int *nums, int size) {
    if (0 == head->capacity) {
        array_init(head);
    }

    if (head->size == head->capacity) {
        head->capacity *= 2;
        head->array = (int **)realloc(head->array, sizeof(int *) * head->capacity);
        head->cols  = (int *)realloc(head->cols, sizeof(int) * head->capacity);
    }

    head->array[head->size] = (int *)malloc(sizeof(int) * size);
    memcpy(head->array[head->size], nums, sizeof(int) * size);
    head->cols[head->size++] = size;

    return 0;
}

int
array_append_without_same(struct ArrayHead *head, int *nums, int size) {
    int i, j;
    if (0 == head->capacity) {
        array_init(head);
    }

    if (head->size == head->capacity) {
        head->capacity *= 2;
        head->array = (int **)realloc(head->array, sizeof(int *) * head->capacity);
        head->cols  = (int *)realloc(head->cols, sizeof(int) * head->capacity);
    }

    /* nums is sorted && array[i] is sorted */
    for (i = 0; i < head->size; i++) {
        if (head->cols[i] != size) {
            continue;
        }
        for (j = 0; j < size; j++) {
            if (head->array[i][j] != nums[j]) {
                break;
            }
        }
        if (j == size) {
            return 1;  /* same */
        }
    }
    head->array[head->size] = (int *)malloc(sizeof(int) * size);
    memcpy(head->array[head->size], nums, sizeof(int) * size);
    head->cols[head->size++] = size;

    return 0;
}

void 
array_free(struct ArrayHead *head) {
    int i;
    for (i = 0; i < head->size; i++) {
        free(head->array[i]);
    }
    if (NULL != head->array) {
        free(head->array);
    }
    if (NULL != head->cols) {
        free(head->cols);
    }
    head->size     = 0;
    head->capacity = 0;
}

void 
array_print(const struct ArrayHead *head) {
    int i, j;
    for (i = 0; i < head->size; i++) {
        printf("[");
        for (j = 0; j < head->cols[i]; j++) {
            printf("%d ", head->array[i][j]);
        }
        printf("]\n");
    }
}
