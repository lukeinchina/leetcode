#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RstHead {
    int **pp;
    int *cols;
    int size;
    int capacity;
};

void sort(int *nums, int size) {
    int i, j, tmp, inc = 0;
    for (i = 0; i < size && 0 == inc; i++) {
        inc = 1;
        for (j = 1; j < size-i; j++) {
            if (nums[j-1] > nums[j]) {
                tmp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = tmp;
                inc = 0;
            }
        }
    }
}

void print_array(int *nums, int size) {
    int i;
    if (size == 0) {
        printf("[]\n");
    }
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n': '\t');
    }
}

void result_init(struct RstHead *head, int result_count) {
    head->capacity = result_count;
    head->size     = 0;
    head->pp       = (int **)malloc(sizeof(int *) * head->capacity);
    head->cols     = (int *)malloc(sizeof(int) * head->capacity);
}

void result_append(int *nums, int size, struct RstHead *head) {
    head->cols[head->size] = size;
    head->pp[head->size]   = (int *)malloc(sizeof(int) * size);
    memcpy(head->pp[head->size], nums, sizeof(int) * size);
    head->size += 1;
}

void subsets_with_dup(const int *nums, int size, int idx, int *selected, int count,
     struct RstHead *head) {
    int i, dup = 1;
    if (idx == size) {
        result_append(selected, count, head);
        return;
    }

    for (i = idx; i+1 < size && nums[i] == nums[i+1]; i++) {
        dup += 1;
    }
    /* 不选择 */
    subsets_with_dup(nums, size, idx + dup, selected, count, head);
    /* 选择 */
    for (i = 0; i < dup; i++) {
        selected[count+i] = nums[idx];
        subsets_with_dup(nums, size, idx + dup, selected, count+i+1, head);
    }
    return;
}

int subsets_count(const int *nums, int size) {
    int i, j, dup, total = 1;
    for (i = 0; i < size; i += dup) {
        dup = 1;
        for (j = i; j+1 < size && nums[j] == nums[j+1]; j++) {
            dup += 1;
        }
        total *= (dup+1);
    }
    return total;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *selected = (int *)calloc(numsSize, sizeof(int));
    struct RstHead head = {NULL, 0, 0};
    sort(nums, numsSize);
    *returnSize = subsets_count(nums, numsSize);
    result_init(&head, *returnSize);
    printf("subsets count : %d\n", head.capacity);
    subsets_with_dup(nums, numsSize, 0, selected, 0, &head);
    *returnColumnSizes = head.cols;
    return head.pp;
}

int
main(int argc, char *argv[]) {
    int i, size, *cols, **pp;
    int nums[] = {1, 2, 2};
    sort(nums, sizeof(nums)/sizeof(nums[0]));
    printf("sorted array:");
    print_array(nums, sizeof(nums)/sizeof(nums[0]));
    pp = subsetsWithDup(nums, sizeof(nums)/sizeof(nums[0]), &size, &cols);
    for (i = 0; i < size; i++) {
        print_array(pp[i], cols[i]);
    }
    return 0;
}
