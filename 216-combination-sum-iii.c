#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **array;
    int *cols;
    int size;
    int capacity;
}ResultHead;

void append_solution(ResultHead *head, int nums[], int size) {
    if (head->capacity <= 0) {
        head->capacity = 2;
        head->size  = 0;
        head->cols  = (int *)malloc(sizeof(int) * head->capacity);
        head->array = (int **)malloc(sizeof(int *) * head->capacity);
    } else if (head->size == head->capacity) {
        head->capacity *= 2;
        head->array = (int **)realloc(head->array, sizeof(int **) * head->capacity);
        head->cols  = (int *)realloc(head->cols, sizeof(int *) * head->capacity);
    }
    head->cols[head->size]  = size;
    head->array[head->size] = (int *)malloc(sizeof(nums[0]) * size);
    memcpy(head->array[head->size], nums, sizeof(nums[0]) * size);

    head->size += 1;
    return;
}

void
comb_sum(int k, int n, int visited[], int sum, int index,
        int *stack, int top, ResultHead *head) {
    int i;
    if (top > k || sum > n) {
        return;
    }
    if (top == k && sum == n) {
        append_solution(head, stack, top);
        return;
    }
    for (i = index; i < 10; i++) {
        if (sum + i > n) {
            break;
        }
        if (!visited[i]) {
            visited[i] = 1;
            stack[top] = i;
            comb_sum(k, n, visited, sum + i, i + 1, stack, top + 1, head);
            visited[i]  = 0;
        }
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    ResultHead head = {NULL, NULL, 0, 0};
    int visited[10] = {0};
    int stack[10];

    comb_sum(k, n, visited, 0, 1, stack, 0, &head);
    *returnColumnSizes = head.cols;
    *returnSize        = head.size;
    return head.array;
}

int
main(int argc, char *argv[]) {
    int **pp;
    int *cols;
    int i,j, size = 0;
    if (argc < 3) {
        printf("usage:%s k  n\n", argv[0]);
        return -1;
    }
    pp = combinationSum3(atoi(argv[1]), atoi(argv[2]), &size, &cols);
    for (i = 0; i < size; i++) {
        for (j = 0; j < cols[i]; j++) {
            printf("%d%c", pp[i][j], j+1 == cols[i] ? '\n' : '\t');
        }
    }
    return 0;
}
