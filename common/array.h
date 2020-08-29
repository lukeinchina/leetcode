#ifndef LEET_CODE_COMMON_ARRAY_H_
#define LEET_CODE_COMMON_ARRAY_H_

struct ArrayHead {
    int **array;
    int *cols;
    int size;
    int capacity;
};

int  array_init(struct ArrayHead *head);
void array_free(struct ArrayHead *head);
int  array_append(struct ArrayHead *head, int *nums, int size);
int  array_append_without_same(struct ArrayHead *head, int *nums, int size);
void array_print(const struct ArrayHead *head);

#endif
