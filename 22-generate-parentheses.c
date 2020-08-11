#include <stdio.h>
#include <stdlib.h>


void calc_count(int left, int right, int *count) {
    if (left == 0 && right == 0) {
        *count += 1;
        return ;
    }
    if (left > 0) {
        calc_count(left-1, right, count);
    }
    if (right > 0 && right > left) {
        calc_count(left, right-1, count);
    }
}

void gen_parenthesis(int left, int right, char *bottom, char *top, 
        char **pp, int *idx) {
    if (left == 0 && right == 0) {
        strncpy(pp[*idx], bottom, top-bottom);
        *(pp[*idx] + (top - bottom)) = '\0';
        *idx += 1;
        return ;
    }
    if (left > 0) {
        *top = '(';
        gen_parenthesis(left-1, right, bottom, top+1, pp, idx);
    }
    if (right > 0 && right > left) {
        *top = ')';
        gen_parenthesis(left, right-1, bottom, top+1, pp, idx);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    static char buff[128] = {0};
    char **pp = NULL;
    int i, idx, total;
    i = idx = total = 0;
    calc_count(n, n, &total);
    pp = (char **)malloc(sizeof(char *) * total);
    for (i = 0; i < total; i++) {
        pp[i] = (char *)malloc(2*n + 1);
    }
    gen_parenthesis(n, n, buff, buff, pp, &idx);
    *returnSize = total;
    return pp;
}

int main(int argc, char *argv[]) {
    int n = 0;
    int total = 0;
    char *pp
    if (argc < 2) {
        printf("usage %s n\n", argv[0]);
        return -1;
    }
    n = atoi(argv[1]);
    calc_count(n, n, &total);
    printf("total %d\n", total);
    generateParenthesis(n, &total);
    return 0;
}
