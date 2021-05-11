#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char *s, const char *p) {
    while (s < p) {
        if (*s++ != *p--) {
            return 0;
        }
    }
    return 1;
}

char * shortestPalindrome(char * s){
    int    len = strlen(s);
    int i, add_len;
    const char *end  = s + len - 1;
    const char *p    = end;
    char *pnew = s;

    while (s < p) {
        if (is_palindrome(s, p)) {
            add_len = end - p;
            break;
        }
        p--;
    }
    add_len = end - p;
    pnew = (char *)malloc(len + add_len + 1);
    for (i = 0; i < add_len; i++) {
        pnew[add_len - i - 1] = *(p+i+1);
    }
    strcpy(pnew + add_len, s);
    return pnew;
}

int
main(int argc, char *argv[]) {
    char *p = NULL;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    p =  shortestPalindrome(argv[1]);
    printf("%s\n", p);
    return 0;
}
