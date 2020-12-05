#include <stdio.h>
#include <ctype.h>
#include <string.h>

int lengthOfLastWord(char * s){
    char *end = s + strlen(s) - 1;
    char *begin = end;
    int length = 0;
    for (; end >= s && isspace(*end); end--) {}
    for (begin = end; begin >=s && !isspace(*begin); begin--) {}
    if (begin < end) {
        length = end - begin;
    }
    return length;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
    }
    printf("%d\n", lengthOfLastWord(argv[1]));
    return 0;
}
