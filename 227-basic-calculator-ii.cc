#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define calc_on_top(c) do {\
    if ((c) == '+') { \
        val = nums[ntop-2] + nums[ntop-1]; \
    }else if ((c) == '-') { \
        val = nums[ntop-2] - nums[ntop-1]; \
    }else if ((c) == '*') { \
        val = nums[ntop-2] * nums[ntop-1]; \
    }else if ((c) == '/') { \
        val = nums[ntop-2] / nums[ntop-1]; \
    } \
    nums[ntop-2] = val; \
    ntop -= 1;\
}while (0)

int calculate(char * s){
    int val;
    int nums[16] = {0}, ops[16];
    int ntop = 0, otop = 0;
    while ('\0' != *s) {
        if (isspace(*s)) {
            s++;
            continue;
        } else if (isdigit(*s)) {
            for (val = 0; isdigit(*s); s++) {
                val = val * 10 + (*s - '0');
            }
            nums[ntop++] = val;
        } else if (0 == otop) {
            ops[otop++] = *s++;
        } else if ('+' == *s || '-' == *s) {
            while (otop > 0) {
                calc_on_top(ops[otop-1]);
                otop--;
            }
            ops[otop++] = *s++;
        } else if ('*' == *s || '/' == *s) {
            if (ops[otop-1] == '+' || ops[otop-1] == '-') {
                ops[otop++] = *s++;
            }else {
                calc_on_top(ops[otop-1]);
                ops[otop-1] = *s++;
            }
        }
    }
    while (otop > 0) {
        assert(ntop > 1);
        calc_on_top(ops[otop-1]);
        otop--;
    }
    return nums[0];
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s 'expr'\n", argv[0]);
        return -1;
    }
    printf("%s = %d\n", argv[1], calculate(argv[1]));
    return 0;
}
