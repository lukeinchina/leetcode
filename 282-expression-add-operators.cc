#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

inline
long calc_op(long a, long b, char op) {
    if ('+' == op) {
        return a + b;
    } else if ('*' == op) {
        return a * b;
    } else {
        return a - b;
    }
}

void conv_digit(const string &str, int digits[]) {
    for (int i = 0; i < str.size(); i++) {
        digits[i] = str[i] - '0';
    }
}

int calc_expr(const int *nums, int size, char *ops, int count) {
    long stack[4];
    char op_stack[4];
    char op1, op2;
    int i, top, op_top;
    top = op_top = 0;
    stack[top++]       = nums[0];
    stack[top++]       = nums[1];
    op_stack[op_top++] = ops[0];
    for (i = 1; i < count; i++) {

        op1 = op_stack[op_top-1];
        op2 = ops[i];
        // stack[top++] = nums[i];
        if (op2 == '*' && (op1 == '-' || op1 == '+')) {
            stack[top++]       = nums[i+1];
            op_stack[op_top++] = op2;
            continue;
        }
        stack[top-2] = calc_op(stack[top-2], stack[top-1], op_stack[op_top-1]);
        top--;
        op_top--;
        stack[top++]       = nums[i+1];
        op_stack[op_top++] = op2;
    }

    while (op_top > 0){
        stack[top-2] = calc_op(stack[top-2], stack[top-1], op_stack[op_top-1]);
        top--;
        op_top--;
    }
    return stack[0];
}

void calc_expr_test(int argc, char *argv[]) {
    int nums[16];
    char ops[16];
    int val, size, count;
    const char *p = NULL;
    if (argc < 2) {
        printf("usage:%s expr\n", argv[0]);
    }
    val = size = count = 0;
    for (p = argv[1]; '\0' != *p; p++) {
        if (isdigit(*p)) {
            val = val * 10 + (*p - '0');
        } else {
            nums[size++] = val;
            ops[count++] = *p;
            val = 0;
        }
    }
    /* last digit */
    nums[size++] = val;

    printf("epxr:%s, exec:%d\n", argv[1], calc_expr(nums, size, ops, count));
    return ;
}

void calc_all_expr(const int *nums, int size, char *ops, int count, 
        int target, vector<string> &solutions) {
    if (count+1 == size) {
        if (target == calc_expr(nums, size, ops, count)) {
            printf("solution:");
        }
        return;
    }
    ops[count] = '+';
    calc_all_expr(nums, size, ops, count+1, target, solutions);
    ops[count] = '-';
    calc_all_expr(nums, size, ops, count+1, target, solutions);
    ops[count] = '*';
    calc_all_expr(nums, size, ops, count+1, target, solutions);
}

void add_operators(const char *str, int target, char *stack, int top) {
    if ('\0' == *str) {
        return;
    }
    int val = atoi(str);
    if (val < target) {
        return;
    } else if (val == target) {
        // stack[top] = '\0';
        strcpy(stack+top, str);
        printf("%s\n", stack);
        return ;
    }
    val = 0;
    for (const char *p = str; '\0' != *p; p++) {
        val = val * 10 + (*p - '0');
        stack[top + (p-str)] = *p;
        stack[top + (p-str) + 1] = '+';
        add_operators(p+1, target - val, stack, (p-str) + top + 2);
        stack[top + (p-str) + 1] = '-';
        add_operators(p+1, val - target, stack, (p-str) + top + 2);
        if (val == 0 || (target % val != 0)) {
            continue;
        }
        stack[top + (p-str) + 1] = '*';
        add_operators(p+1, target / val, stack, (p-str) + top + 2);
    }
}

vector<string> addOperators(string num, int target) {
    int size = num.size();
    int nums[12], digits[12];
    char ops[12];
    long i, total = (1L << (size - 1) );
    int j, val, idx;
    vector<string> result;

    conv_digit(num, digits);

    for (i = 0; i < total; i++) {
        val = idx = 0;
        for (j = 0; j < size-1; j++) {
            if ((1 << j) & i) {
                nums[idx++] = val * 10 + digits[j];
                val = 0;
            } else {
                val = val * 10 + digits[j];
            }
        }
        nums[idx++] = val * 10 + digits[j];
        /* debug */
        for (j = 0; j < idx; j++) {
            printf("%d%c", nums[j], j+1 == idx ? '\n' : '\t');
        }

        calc_all_expr(nums, size, ops, 0, target, result);
    }

    return result;
}

int
main(int argc, char *argv[]) {
    // calc_expr_test(argc, argv);
    char stack[1024];
    if (argc < 3) {
        printf("usage:%s expr  n\n", argv[0]);
        return -1;
    }
//    vector<string> results = addOperators(string(argv[1]), atoi(argv[2]));
    add_operators(argv[1], atoi(argv[2]), stack, 0);

    
    return 0;
}
