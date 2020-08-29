#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/* Sunday 算法 */
int strStr(const char * haystack, const char * needle){
    int index[26] = {0};
    const char *p  = needle;
    const char *s  = haystack;
    const char *end = strlen(s) + s;
    int i, len;

    if ('\0' == *p) {
        return 0;
    }
    /* 计算每个字符第一次出现位置, 0表示没有出现 */
    for (len = 0; '\0' != *p; p++) {
        index[*p - 'a'] = ++len;
    }

    if (len > (end - s)) {
        return -1;
    }

    while (s < end) {
        p = needle;
        for (i = 0; i < len && s+i < end && (*(s+i) == *(p+i)); i++) {
        }
        if (i == len) {
            return s - haystack;
        }

        /* 不匹配. */
        if (s+len >= end) {
            return -1;
        }
        s += len + 1 - index[*(s+len) - 'a'];
    }
    return -1;
}

int
main(void) {
    printf("%d\n", 5 / -3);
    printf("%d\n", -5 / 3);
    printf("%d\n", -5 / -3);
    printf("%d\n", -1 / 3);
    printf("%s find %s = %d\n", "hello", "ll", strStr("hello", "ll"));
    printf("%s find %s = %d\n", "aaa", "aaaa", strStr("aaa", "aaaa"));
    printf("%s find %s = %d\n", "mississippi", "issip", strStr("mississippi", "ippi"));
    return 0;
}
