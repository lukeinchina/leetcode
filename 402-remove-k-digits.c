#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * trim_leading(char *str) {
    char *p = str;
    char *q = str;
    while ('0' == *q) {
        q++;
    }
    if ('\0' == *q) {
        *p++ = '0';
    }
    while ('\0' != *q) {
        *p++ = *q++;
    }
    *p = '\0';
    return str;
}
char * removeKdigits(char * num, int k){
    int len = strlen(num);
    char *dst = (char *)malloc(len + 2 - k);
    char *stack, *p = dst;
    int i = 0, top = 0, ndel = 0;
    
    if (k >= len) {
        *p++ = '0';
        *p = '\0';
        return dst;
    }

    stack = (char *)malloc(len);
    stack[top++] = *num++;
    for (; '\0' != *num; num++) {
        while (top > 0 && stack[top-1] > *num) {
            top--;
            if (++ndel == k) {
                /* 栈中剩余元素+尚未处理字符, 即为目标串 */
                while (i < top) {
                    *p++ = stack[i++];
                }
                while('\0' != *num) {
                    *p++ = *num++;
                }
                *p = '\0';
                return trim_leading(dst);
            }
        }
        stack[top++] = *num;
    }
    /* 取栈中的 前 n个字符即是 */
    while (i < top && i < (len - k)) {
        *p++ = stack[i++];
    }
    *p = '\0';

    free(stack);

    return trim_leading(dst);
}

int
main(int argc, char *argv[]) {
    char num[] = {"1000"}; 
    char *str =  NULL;
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    str = removeKdigits(num, atoi(argv[1]));

    printf("%s\n", str);
    free(str);
    return 0;
}
