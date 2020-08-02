#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <limits.h>

int myatoi(char * str){
    /* trim */
    long val  = 0;
    int  flag = 1;
    while ('\0' != str && isspace(*str)) {
        str++;
    }
    /* sign */
    if ('+' == *str) {
        str++;
    } else if ('-' == *str) {
        flag = -1;
        str++;
    }
    for (; '\0' != *str && isdigit(*str); str++) {
        val = val * 10 + flag * (*str - '0');
        if (val > INT_MAX) {
            return INT_MAX;
        } else if (val < INT_MIN) {
            return INT_MIN;
        }
    }
    return (int) val;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s int\n", argv[0]);
        return -1;
    }

    printf("%s atoi  %d\n", argv[1], myatoi(argv[1]));

    return 0;
}
