#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define calc() do {\
            if ('+' == op){\
                res += val;\
            } else if ('-' == op) {\
                res -= val;\
            }\
}while (0)

const char *
helper(const char *s, long *ret) {
    char op = '+';
    long val, res = 0;
    while ('\0' != *s) {
        if (isspace(*s)) {
            s++;
        } else if (')' == *s) {
            s++;
            break;
        } else if ('(' == *s) {
            s = helper(s+1, &val);
            calc();
        } else if ('+' == *s || '-' == *s) {
            op = *s++;
        } else {
            /* digits */
            for (val = 0; '\0' != *s && isdigit(*s); s++) {
                val = val * 10 + (*s - '0');
            }
            calc();
        }
    }

    *ret = res;
    return s;
}

int calculate(char * s){
    long ret = 0;
    helper(s, &ret);
    return (int)ret;
}
