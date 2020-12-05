#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b){
    int alen = strlen(a);
    int blen = strlen(b);
    int len = (alen > blen ? alen : blen) + 2;
    char *p = (char *)calloc(len, 1);
    char *aend = a + alen - 1;
    char *bend = b + blen - 1;
    char *end = p + len - 2;
    int flag = 0;
    int v    = 0;
    while (aend >= a && bend >= b) {
        v = (*aend - '0') + (*bend - '0') + flag;
        flag = (v / 2);
        *end-- = (v % 2) + '0';
        aend--;
        bend--;
    }
    while (aend >= a) {
        v = (*aend-- - '0')  + flag;
        flag = (v / 2);
        *end-- = (v % 2) + '0';
    }
    while (bend >= b) {
        v = (*bend-- - '0') + flag;
        flag = (v / 2);
        *end-- = (v % 2) + '0';
    }
    if (flag) {
        *end = '1';
    } else {
        memmove(p, end+1, len-1);
    }
    return p;
}

int 
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s b1 b2\n", argv[0]);
        return -1;
    }
    printf("%s\n", addBinary(argv[1], argv[2]));
    return 0;
}
