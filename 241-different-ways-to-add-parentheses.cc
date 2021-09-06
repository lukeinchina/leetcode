#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;


int max_count(int n) {
    int i, j, total;
    int nums[32] = {1, 1, 2, 5};
    for (i = 4; i <= n; i++) {
        total = 0;
        for (j = 0; j <= i; j++) {
            total += nums[j] * (i-1-j);
        }
    }
    return nums[n];
}
/*------------------------------------------------------*/

int parse_expr(const char *str, int nums[], char ops[]) {
    int val, top, op_top;
    top = op_top = 0;
    while ('\0' != *str) {
        if (isdigit(*str)) {
            for (val = 0; isdigit(*str); str++) {
                val = 10 * val + (*str - '0');
            }
            nums[top++] = val;
        } else {
            ops[op_top++] = *str++;
        }
    }
    assert(top = op_top+1);
    return top;
}

inline int calc_op(char op, int a, int b) {
    if ('+' == op) {
        return a + b;
    } else if ('-' == op) {
        return a - b;
    } else if ('*' == op) {
        return a * b;
    }
    return 0;
}

int append_with_dup(char op, const vector<int> &left, const vector<int> &right,
        vector<int> &all) {
    int val;
    int lsize = left.size();
    int rsize = right.size();
    for (int i = 0; i < lsize; i++) {
        for (int j = 0; j < rsize; j++) {
            val = calc_op(op, left[i], right[j]);
            all.push_back(val);
        }
    }
    return 0;
}

int append_without_dup(char op, const vector<int> &left, const vector<int> &right,
        vector<int> &all) {
    int val;
    int lsize = left.size();
    int rsize = right.size();
    for (int i = 0; i < lsize; i++) {
        for (int j = 0; j < rsize; j++) {
            val = calc_op(op, left[i], right[j]);
            all.push_back(val);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    return 0;
}

/* n: size of nums */
void calc_all(char ops[], int nums[], int n, vector<int> &all) {
    if (1 == n) {
        all.push_back(nums[0]);
    } else if (2 == n) {
        all.push_back(calc_op(ops[0], nums[0], nums[1]));
    } else {
        vector<int> left, right;
        for (int i = 0; i < n-1; i++) {
            left.clear();
            right.clear();
            calc_all(ops, nums, i+1, left);
            /* 以 op[i] 为最后一个计算 */
            calc_all(ops+i+1, nums+i+1, n-1-i, right);
            append_with_dup(ops[i], left, right, all);
        }
    }
}

vector<int> diffWaysToCompute(string expression) {
    int nums[32];
    char ops[32];
    vector<int> all;
    int n = parse_expr(expression.c_str(), nums, ops);
    calc_all(ops, nums, n, all);
    printf("total:%ld\n", all.size());
    for (size_t i = 0; i < all.size(); i++) {
        printf("%d\n", all[i]);
    }
    return all;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s expr\n", argv[0]);
        return 1;
    }
    vector<int> results = diffWaysToCompute(argv[1]);
    return 0;
}
