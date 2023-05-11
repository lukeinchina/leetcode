#ifndef _BIN_HEAP_H_
#define _BIN_HEAP_H_

typedef int HeapType;

struct HeapStruct {
    int       size;
    int       capacity;
    HeapType *elems;
};

typedef struct HeapStruct *PriorityQueue;

int  min_heap_init(PriorityQueue q, int max);
void min_heap_uninit(PriorityQueue q);
void min_heap_clear(PriorityQueue q);
void min_heap_insert(PriorityQueue q, HeapType elem);
HeapType min_heap_top(PriorityQueue q);
HeapType min_heap_pop(PriorityQueue q);
int  min_heap_empty(PriorityQueue q);

int  max_heap_init(PriorityQueue q, int max);
void max_heap_uninit(PriorityQueue q);
void max_heap_clear(PriorityQueue q);
void max_heap_insert(PriorityQueue q, HeapType elem);
HeapType max_heap_top(PriorityQueue q);
HeapType max_heap_pop(PriorityQueue q);
int  max_heap_empty(PriorityQueue q);

#endif
