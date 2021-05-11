#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*-------------------------------------------------------------------*/
struct StrVector {
    char **strs;
    int size;
    int capacity;
};

static int 
strvec_init(struct StrVector *head) {
    head->size     = 0;
    head->capacity = 8;
    head->strs = (char **)malloc(sizeof(char*) * head->capacity);
    return 0;
}

static int 
strvec_append(struct StrVector *head, const char *str) {
    if (0 == head->capacity) {
        strvec_init(head);
    }

    if (head->size == head->capacity) {
        head->capacity *= 2;
        head->strs = (char **)realloc(head->strs, sizeof(char *) * head->capacity);
    }
    head->strs[head->size++] = strdup(str);

    return 0;
}

typedef char** Group;
struct GroupVec {
    Group *vec;
    int *lengths;
    int size;
    int capacity;
};

static int 
groupvec_init(struct GroupVec *head) {
    head->size     = 0;
    head->capacity = 8;
    head->vec      = (Group *)malloc(sizeof(Group)  * head->capacity);
    head->lengths  = (int *)malloc(sizeof(int)  * head->capacity);
    return 0;
}

static int 
groupvec_append(struct GroupVec *head, struct StrVector *h) {
    if (0 == head->capacity) {
        groupvec_init(head);
    }

    if (head->size == head->capacity) {
        head->capacity *= 2;
        head->vec     = (Group *)realloc(head->vec, sizeof(Group) * head->capacity);
        head->lengths = (int *)realloc(head->lengths, sizeof(int)  * head->capacity);
    }
    head->vec[head->size]   = h->strs;
    head->lengths[head->size] = h->size;
    head->size += 1;

    return 0;
}
/*-------------------------------------------------------------------*/
long long
hash_dict(const char *str, int *dict, int size) {
    long long v = 0L;
    memset(dict, 0, size);
    for (; '\0' != *str; str++) {
        assert(*str-'a' <= 26);
        assert(*str-'a' >= 0);
        dict[(*str-'a')] += 1;
        v += *str;
    }
    return v;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    const static int SIZE = 26;
    int i, j, h1, h2;
    int dict[SIZE], map[SIZE];
    struct StrVector str_array = {NULL, 0, 0};
    struct GroupVec  res_array = {NULL, NULL, 0, 0};

    int *used = (int *)malloc(sizeof(int) * strsSize);
    memset(used, 0, sizeof(int) * strsSize);

    for (i = 0; i < strsSize; i++) {
        /* 先找到一个没有归类的元素,作为种子 */
        for (; used[i] && i < strsSize; i++)  {}
        if (i >= strsSize) {
            break;
        }
        h1 = hash_dict(strs[i], dict, sizeof(dict));
        printf("[%s]\n", strs[i]);

        memset(&str_array, 0, sizeof(str_array));
        strvec_init(&str_array);
        strvec_append(&str_array, strs[i]);

        /* 找到和种子包含字母相同的元素 */
        for (j = i+1; j < strsSize; j++) {
            if (used[j]) {
                continue;
            }
            h2 = hash_dict(strs[j], map, sizeof(map));
            if (h1 == h2 && (memcmp(dict, map, sizeof(map)) == 0)) {
                printf("[%s]\n", strs[j]);
                strvec_append(&str_array, strs[j]);
                used[j] = 1;
            }
        }
        printf("-------\n");
        used[i] = 1; /* used */

        groupvec_append(&res_array, &str_array);
    }
    free(used);

    *returnSize = res_array.size;
    *returnColumnSizes = res_array.lengths;
    return res_array.vec;
}

int
main(void) {
    // char *strs[] = { "eat","tea","tan","ate","nat","bat" };
    char *strs[] = {"",""};
    int i,j;
    int size;
    int *colsizes;
    char ***results = groupAnagrams(strs, sizeof(strs)/sizeof(strs[0]), &size, &colsizes);
    
    for (i = 0; i < size; i++) {
        printf("----------[%d]----------\n", i);
        for (j = 0; j < colsizes[i]; j++) {
            printf("%s\n", results[i][j]);
        }
        printf("\n");
    }
    return 0;
}
