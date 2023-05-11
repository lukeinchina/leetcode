#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Result {
    char letters[26];
    int  size;
    int  capacity;
    long rn;      /* 逆序数 */
};

/* 没有重复元素，直接追加在末尾，同时更新逆序数 */
void rdl_append(struct Result *p, char c) {
    for (int i = 0; i < p->size; i++) {
        if (p->letters[i] > c) {
            p->rn += 1;
        }
    }
    p->letters[p->size++] = c; 
}

/* 指定元素挪到最后一个位置 */
void rdl_move_to_last(char *s, int size, int index) {
    char c = s[index];
    for (int i = index; i+1 < size; i++) {
        s[i] = s[i+1];
    }
    s[size-1] = c;
}

int rn_for_change(const char *s, int size, int index) {
    char c = s[index];
    int i, a = 0, b = 0;
    for (i = index+1; i < size; i++) {
        if (s[i] < c) {
            a++;
        }
        if (s[i] > c) {
            b++;
        }
    }
    return b - a;
}

char * removeDuplicateLetters(char * s){
    int i, top = 0, cnt = 0;
    char *dst, *p = s;
    char dict[26] = {0};
    char stack[26];
    for (; '\0' != *p; p++) {
        dict[*p - 'a']  += 1;
    }
    for (i = 0; i < 26; i++) {
        if (dict[i] > 0) {
            cnt += 1;
        }
    }
    stack[top++] = *s++;
    for (; '\0' != *s; s++) {
        if (--dict[*s -'a'] == 0) {
            stack[top++] = *s++;
            continue;
        } 
        /* 当前栈顶元素大于 *s，且后面还有栈顶元素时，出栈 */
        while (top > 1 && stack[top-1] > *s && dict[stack[top-1]] > 0) {
            top--;
        }
    }
    dst = (char *)calloc(cnt + 1, 1);
    return dst;
}

int
main(int argc, char *argv[]) {
    char *str;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    str = removeDuplicateLetters(argv[1]);
    printf("%s\n", str);
    return 0;
}
