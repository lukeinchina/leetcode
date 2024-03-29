#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

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

long calc(const char * s) {
    long  nums[16] = {0};
    char ops[16];
    long val, ntop = 0, otop = 0;
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

inline void check_candidate(const char *expr, int target, vector<string> &dst) {
    if (calc(expr) == target) {
        dst.push_back(expr);
        printf("%s -->(%ld)\n", expr, calc(expr));
    }
    return ;
}

void backtrack(const char *s, char *t, char *expr, int lead, int target, vector<string> &dst) {
    int i;
    static const char ops[] = {'+', '-', '*'};
    if ('\0' == *s) {
        *t = '\0';
        return check_candidate(expr, target, dst);
    } else if ('\0' == *(s+1)) {
        *t = *s;
        *(t+1) = '\0';
        return check_candidate(expr, target, dst);
    }
    *t = *s;
    for (i = 0; i < 3; i++) {
        *(t+1) = ops[i];
        backtrack(s+1, t+2, expr, 1, target, dst); 
    }

    if (lead && '0' == *s) {
        return;
    }
    return backtrack(s+1, t+1, expr, 0, target, dst);
}

vector<string> addOperators(string num, int target) {
    char expr[32];
    vector<string> dst;
    backtrack(num.c_str(), expr, expr, 1, target, dst);
    return dst;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s expr  n\n", argv[0]);
        return -1;
    }
    vector<string> results = addOperators(string(argv[1]), atoi(argv[2]));
    
    return 0;
}
