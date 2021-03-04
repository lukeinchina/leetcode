#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
next_step(char *p) {
    while ('\0' != *p && '.' != *p) {
        p++;
    }
    p += ('.' == *p) ? 1 : 0;
    return p;
}

int compareVersion(char * version1, char * version2){
    char *p = version1;
    char *q = version2;
    int a = 0;
    int b = 0;
    while (('\0' != *p || '\0' != *q) && a == b) {
        a = b = 0;
        if ('\0' != *p) {
            a = atoi(p);
            p = next_step(p);
        }

        if ('\0' != *q) {
            b = atoi(q);
            q = next_step(q);
        }
    }
    return a-b > 0 ? 1 : (a-b < 0 ? -1 : 0);
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s ver1  ver2\n", argv[0]);
        return -1;
    }
    printf("%d\n", compareVersion(argv[1], argv[2]));
    return 0;
}
