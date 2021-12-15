#include <stdio.h>
#include <stdlib.h>

char * removeDuplicateLetters(char * s){
    int i, n = 0;
    int dict[26] = {0};
    char *str;
    for (; '\0' != *s; s++) {
        dict[*s - 'a'] = 1;
    }
    for(i = 0; i < 26; i++) {
        n += dict[i];
    }
    str = (char *)malloc(n+1);
    n   = 0;
    for (i = 0; i < 26; i++) {
        if (0 != dict[i]) {
            str[n++] = 'a' + i;
        }
    }
    str[n] = '\0';
    return str;
}

int
main(int argc, char *argv[]) {
    char *str;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    str = removeDuplicateLetters(argv[1]);
    printf("%s\n", str);
    return 0;
}
