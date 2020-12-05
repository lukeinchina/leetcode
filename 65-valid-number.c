#include <stdio.h>
#include <ctype.h>

char * over_num(char *s, int *isnum) {
    *isnum = 0;
    if ('-' == *s || '+' == *s) {
        s++;
    }

    while (isdigit(*s)) {
        *isnum = 1;
        s++;
    }
    return s;
}

bool isNumber(char * s){
    int isnum = 0;

    while (' ' == *s) {
        s++;
    }

    s = over_num(s, &isnum);

    // 允许出现一个小数点
    if ('.' == *s) {
        s++;
    }

    // 小数部分
    while (isdigit(*s)) {
        isnum = 1;
        s++;
    }

    // 允许出现科学计数法，其前必须为数字
    if (isnum && 'e' == *s) {
        isnum = 0;
        s = over_num(s+1, &isnum);
    }

    while (' ' == *s) {
        s++;
    }

    return '\0' == *s && isnum;
}
