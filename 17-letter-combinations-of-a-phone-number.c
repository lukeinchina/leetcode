#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const static char *mapping[10] = {
    "", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};
const static int counts[10] = {
    0, 0, 3, 3, 3, 3, 3, 4, 3, 4
};

int calc_count(const char *digits, const int *counts) {
    if ('\0' == *digits) {
        return 1;
    }
    return counts[*digits - '0'] * calc_count(digits+1, counts);
}

void create_combinations(const char *digits, int len, char *begin, 
        char *end, char **dst, int *idx) {
    const char *p = NULL;
    if ('\0' == *digits) {
        /* get one */
        dst[*idx] = (char *)malloc(len+1);
        dst[*idx][len] = '\0';
        strncpy(dst[*idx], begin, end-begin);
        *idx += 1;
        return;
    }
    
    for (p = mapping[*digits-'0']; '\0' != *p; p++) {
        *end = *p;
        create_combinations(digits+1, len, begin, end+1, dst, idx);
    }
}

char ** letterCombinations(char * digits, int* returnSize){

    char letters[12];
    int  idx  = 0;
    int  size = calc_count(digits, counts);
    char **pp = (char **)malloc(sizeof(char *) * size);

    *returnSize = size;
    create_combinations(digits, strlen(digits), letters, letters, pp, &idx);
    return pp;
}

int main(void) {
    int i;
    int total = 0;
    char **pp = letterCombinations("3", &total);
    printf("total:%d\n", total);
    for (i = 0; i < total; i++) {
        printf("%s\n", pp[i]);
    }
    return 0;
}
