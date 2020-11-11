#include <stdio.h>

bool matchstar(char *s, char *p);

bool matchhere(char *s, char *p) {
    if ('\0' == *s && '\0' == *p) {
        return true;
    }
    if ('\0' == *p) {
        return false;
    }
    if ('*' == *p) {
        return matchstar(s, p+1);
    }
    if ('\0' != *s && (*p == *s || '?' == *p)) {
        return matchhere(s+1, p+1);
    }
    return false;
}

bool matchstar(char *s, char *p) {
    do {
        if (matchhere(s, p)) {
            return true;
        }
    }while ('\0' != *s++);
    return false;
}
bool isMatch(char * s, char * p){
    return matchhere(s, p);
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s text regex\n", argv[0]);
        return 0;
    }
    printf("%s %s : %d\n", argv[1], argv[2], isMatch(argv[1], argv[2]));
    return 0;
}
