#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * multiply(char * num1, char * num2){
    int i, val, flag;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total = len1+len2;
    char *dst = (char *)malloc(total + 1);
    char *tmp = (char *)malloc(len1 + 2);
    memset(dst, '0', total+1);
    dst[total] = '\0';
    char *q, *p, *t,  c;
    for (i = len2-1; i >= 0; i--) {

        memset(tmp, '0', len1+2);
        tmp[len1+1] = '\0';
        /* 当前轮乘法 */
        t = tmp + len1;
        flag = 0;
        c = num2[i];
        p = num1 + len1 -1;
        for (; p >= num1; p--) {
            val = flag + (c-'0') * (*p - '0');
            flag = val / 10;
            val = val % 10;

            *t-- = (val + '0');
        }
        if (flag) {
            *t = (flag + '0');
        }

        /* 和历史值相加 */
        flag = 0;
        q = dst + total - (len2 - i);
        for (t = tmp + len1; t >= tmp; t--) {
            val = flag + (*q - '0') + (*t - '0');
            flag = val / 10;
            val  %= 10;
            *q-- = val + '0';
        }
        if (flag) {
            *q = flag + '0';
        } else {
            q += 1;
        }
        // printf("\n---%s\n", q);
    }
    for (p = dst; '0' == *p && p <= dst+total; p++) {}
    if (p == dst+total) {
        dst[1] = '\0';
    }else {
        memmove(dst, p, total - (p - dst));
        dst[total - (p - dst)] = '\0';
    }
    free(tmp);
    return dst;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s num1 num2\n", argv[0]);
        return -1;
    }

    printf("%s\n", multiply(argv[1], argv[2]));
    return 0;
}
