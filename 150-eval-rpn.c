#include <stdio.h>
#include <stdlib.h>

int evalRPN(char **tokens, int tokensSize) {
    char c;
    int i, top, val;
    int *stack = (int *)malloc(sizeof(int) * tokensSize);

    for (top = i = 0; i < tokensSize; i++) {
        c = tokens[i][0];
        if ('+' != c && '*' != c && '/' != c 
                && ('-' != c || '\0' != tokens[i][1])) {
            stack[top++] = atoi(tokens[i]);
            continue;
        }
        val = stack[--top];
        switch (c) {
            case '+':
                stack[top-1] += val; break;
            case '-':
                stack[top-1] -= val; break;
            case '*':
                stack[top-1] *= val; break;
            case '/':
                stack[top-1] /= val; break;
            default:
                break;
        }
    }
    val = stack[0];
    free(stack);
    return val;
}

int
main(void) {
    char *strs[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    printf("%d\n", evalRPN(strs, sizeof(strs) / sizeof(strs[0])));
    return 0;
}
