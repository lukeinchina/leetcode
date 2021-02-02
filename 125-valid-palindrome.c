#include <stdio.h>

#include <stdlib.h>

bool isPalindrome(char * s){
    char *p = s;
    for (; '\0' != *p; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p += ('a' - 'A');
        }
    }
    --p;
    while (s < p) {
        if (*s < '0' || (*s > '9' && *s < 'a') || *s > 'z') {
            s++;
        } else if (*p < '0' || (*p > '9' && *p < 'a') || *p > 'z') {
            p--;
        } else if (*p == *s) {
            s++;
            p--;
        } else {
            return false;
        }
    }
    return true;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
    printf("result:%d\n", isPalindrome(argv[1]));
    return 0;
}
