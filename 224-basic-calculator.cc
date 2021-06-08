#include <string.h>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

#define calc_on_stack(ops, nums) do { \
                ch = ops.top(); \
                val = nums.top(); \
                nums.pop(); \
                n = nums.top(); \
                nums.pop(); \
                n = calc_op(n, val, ch); \
                nums.push(n); \
                ops.pop(); \
}while (0)

inline
long calc_op(long a, long b, char op) {
    if ('+' == op) {
        return a + b;
    } else if ('*' == op) {
        return a * b;
    }
    return 0;
}

const char *
get_val(const char *str, long &val) {
    for (val = 0; isdigit(*str); str++) {
        val = val * 10 + (*str - '0');
    }
    return str;
}

int calculate(string s) {
    char ch;
    long n, val;
    stack<long> nums;
    stack<char> ops;
    const char *str = s.c_str();
    while ('\0' != *str) {
        while(isspace(*str)) {
            str++;
        }
        if (isdigit(*str)) {
            str = get_val(str, val);
            while (!ops.empty() && '(' != ops.top()) {
                ch = ops.top();
                n = nums.top();
                val = calc_op(n, val, ch);
                nums.pop();
                ops.pop();
            }
            nums.push(val);
        } else if ('(' == *str) {
            ops.push(*str++);
        }else if (')' == *str) {
            while (!ops.empty() && '(' != ops.top()) {
                calc_on_stack(ops, nums);
            }
            ops.pop(); /* '(' */
            str++;
        } else if ('+' == *str ) {
            ops.push(*str++);
        } else if ('-' == *str) {
            if (!nums.empty()) {
                ops.push('+');
            }
            ops.push('*');
            nums.push(-1);
            str++;
        }
    }
    while (nums.size() > 1) {
        calc_on_stack(ops, nums);
    }
    n = nums.top();
    return n;
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
