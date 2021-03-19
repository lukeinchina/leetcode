#include <stdio.h>

bool helper(char * s, char * t){
    char map[128] = {0};

    while ('\0' != *s && '\0' != *t) {
        if (map[*s] == 0) {
            map[*s] = *t;
        } else if (map[*s] != *t) {
            return false;
        }
        s++;
        t++;
    }
    return true;
}

bool isIsomorphic(char * s, char * t){
    return helper(s, t) && helper(t, s);
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s s t\n", argv[0]);
        return -1;
    }
    printf("%d\n", isIsomorphic(argv[1], argv[2]));
    return 0;
}
