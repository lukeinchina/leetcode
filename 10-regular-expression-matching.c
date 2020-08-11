#include <string.h>
#include <stdio.h>

bool matchstar(char c, char *text, char *p);
bool isMatch(char * s, char * p){
    if ('\0' == *s && '\0' == *p) {
        return true;
    }
    if ('\0' == *p) {
        return false;
    }
    if ('*' == *(p+1)) {
        return matchstar(*p, s, p+2);
    }
    if ('\0' != *s && (*s == *p || '.' == *p)) {
        return isMatch(s+1, p+1);
    }
    return false;
}

bool matchstar(char c, char *text, char *p) {
    do {
        if (isMatch(text, p)) {
            return true;
        }
    }while ('\0' != *text && (c == *text++ || '.' == c));
    return false;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s string patten\n", argv[0]);
        return -1;
    }
    printf("%s %s is %d\n", argv[1], argv[2], isMatch(argv[1], argv[2]));
    return 0;
}
