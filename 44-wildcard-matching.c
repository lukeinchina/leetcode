#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 该递归算法正确性OK，但超时.
 */
/*
bool matchstar(char *s, char *p);

bool matchhere(char *s, char *p) {
    if ('\0' == *p) {
        return '\0' == *s;
    }
    if ('*' == *p) {
        return matchstar(s, p+1);
    }
    if ('\0' != *s && (*p == *s || '?' == *p)) {
        return matchhere(s+1, p+1);
    }
    return false;
}

bool matchstar(char *s, char *p) {
    do {
        if (matchhere(s, p)) {
            return true;
        }
    }while ('\0' != *s++);
    return false;
}
*/
char *merge_multi_star(char *p) {
    char *fast = p;
    char *slow = p;
    while ('\0' != *fast) {
        if ('*' == *fast && *(fast+1) == *fast) {
            fast++;
        } else {
            *slow++ = *fast++;
        }
    }
    *slow = '\0';
    return p;
}

char *
str_find(char *s, char *p) {
    char *str, *q;
    for (; '\0' != *s; s++) {
        for (str = s, q = p; '\0' != *str && '\0' != *q; q++, str++) {
            if ('?' != *q && *str != *q) {
                break;
            }
        }
        /*匹配上，返回值是下一个位置 */
        if ('\0' == *q) {
            return str;
        }
        /* s的长度小于 p*/
        if ('\0' == *str) {
            return NULL;
        }
    }
    return NULL;
}

/* p: "*a*b*c*" */
bool match_star_patten(char *s, char *p) {
    char *begin, *find;
    printf("[%s] [%s] calc:\n", s, p);
    while ('\0' != *p) {
        /* skip '*' */
        for (; '\0' != *p && '*' == *p; p++) {}
        if ('\0' == *p) {
            return true;
        }
        begin = p;
        for (; '\0' != *p && '*' != *p; p++) {}
        *p = '\0'; /* make a string */
        find = str_find(s, begin);
        if (NULL == find) {
            return false;
        }
        s = find;
        *p = '*'; /* restore */
    }
    return false;
}

bool isMatch(char * s, char * p){
    char *pend, *send;

    merge_multi_star(p);
    pend   = p + strlen(p);
    send   = s + strlen(s);
    
    printf("%s----\n", p);
    /* 第一个*前面所有字符必须匹配开头 */
    for (; p < pend && '*' != *p; p++, s++) {
        if (s >= send || ('?' != *p && *s != *p)) {
            return false;
        }
    }
    /* 最后一个*后面的字符必须尾部匹配 */
    for (pend--, send--; pend >= p && '*' != *pend ; pend--, send--) {
        if (send < s || ('?' != *pend && *send != *pend)) {
            return false;
        }
        /* note 改变了s和p原值 */
        *pend = *send = '\0';
    }
    /* pend send 都在\0 前一个位置 */
    
    if ('\0' == *p) {
        return '\0' == *s;
    } else { /* '*' == *p */
        return match_star_patten(s, p);
    }
    return false;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s text regex\n", argv[0]);
        return 0;
    }
    // isMatch(argv[1], argv[2]);
    printf("%s %s : %d\n", argv[1], argv[2], isMatch(argv[1], argv[2]));
    return 0;
}
