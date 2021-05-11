#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *elems;
    int size;
    int capacity;
}Heap;

Heap *
heap_init(Heap *h, int count) {
    h->capacity = count + 1;
    h->size     = 0;
    h->elems    = (int *)malloc(sizeof(int) * h->capacity);

    h->elems[h->size++] = INT_MIN;

    return h;
}

Heap *
heap_uninit(Heap *h) {
    free(h->elems);
    return h;
}

int
heap_insert(Heap *h, int x) {
    int i;
    if (h->size == h->capacity) {
        return -1;
    }
    for (i = h->size; h->elems[i >> 1] > x; i >>= 1) {
        h->elems[i] = h->elems[i >> 1];
    }
    h->elems[i] = x;
    h->size++;

    return 0;
}

int heap_del_min(Heap *h) {
    int i, child, last;
    if (h->size < 1) {
        return -1;
    }
    last = h->elems[h->size - 1];
    for (i = 1; (i << 1) < h->size; i = child) {
        child = (i << 1);
        child += child+1 < h->size && h->elems[child] > h->elems[child+1];
        if (h->elems[child] < last) {
            h->elems[i] = h->elems[child];
        } else {
            break;
        }
    }
    h->elems[i] = last;
    h->size--;
    return 0;
}

int heap_get_min(Heap *h) {
    return h->elems[1];
}

int findKthLargest(int* nums, int numsSize, int k){
    int i, x = 0;
    Heap h = {NULL, 0, 0};
    heap_init(&h, k);

    for (i = 0; i < k; i++) {
        heap_insert(&h, nums[i]);
    }

    x = heap_get_min(&h);
    for (i = k; i < numsSize; i++) {
        if (nums[i] > x) {
            heap_del_min(&h);
            heap_insert(&h, nums[i]);
            x = heap_get_min(&h);
        }
    }

    x = heap_get_min(&h);
    heap_uninit(&h);
    return x;
}

void heap_sort(int *nums, int size) {
    int i;
    Heap h = {NULL, 0, 0};
    heap_init(&h, size);

    for (i = 0; i < size; i++) {
        heap_insert(&h, nums[i]);
    }
    for (i = 0; i < size; i++) {
        nums[i] = heap_get_min(&h);
        heap_del_min(&h);
    }

    heap_uninit(&h);
}

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(int argc, char *argv[]) {
    int k = 1;
    int nums[] = {10, 1, 11, 8, 18, 5, 15, 3, 19, 20};
    if (argc < 2) {
        printf("Usage:%s k\n", argv[0]);
        return -1;
    }
    k = atoi(argv[1]);
    heap_sort(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    
    printf("K-th:%d\n", findKthLargest(nums, sizeof(nums) / sizeof(nums[0]), k));
    return 0;
}
