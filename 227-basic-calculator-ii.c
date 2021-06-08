#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
long calc_op(long a, long b, char op) {
    if ('+' == op) {
        return a + b;
    } else if ('-' == op) {
        return a - b;
    } else if ('*' == op) {
        return a * b;
    } else if ('/' == op) {
        return a / b;
    }
    return 0L;
}

#define calc_on_stack(op, num) do {\
                op--;\
                num--;\
                n = calc_op(*(num-1), *num, *op);\
                *(num-1) = n;\
}while (0)

int calculate(char * s){
    char op_buff[8];
    long num_buff[8];
    char *op  = op_buff;
    long *num = num_buff;

    long val, n = 0;
    while ('\0' != *s) {
        val = 0;
        while (isspace(*s)) {
            s++;
        }
        while (isdigit(*s)) {
            val = val * 10 + (*s++ - '0');
            if (!isdigit(*s)) {
                *num++ = val;
            }
        }
        if ('-' == *s || '+' == *s) {
            while (op > op_buff) {
                calc_on_stack(op, num);
            }
            *op++ = *s++;
        } else if ('*' == *s || '/' == *s) {
            if (op > op_buff && ('*' == *(op-1) || '/' == *(op-1))) {
                calc_on_stack(op, num);
            }
            *op++ = *s++;
        }
    }
    while (op > op_buff) {
        calc_on_stack(op, num);
    }
    return num_buff[0];
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s expr\n", argv[0]);
        return -1;
    }
    printf("%d\n", calculate(argv[1]));
    return 0;
}
