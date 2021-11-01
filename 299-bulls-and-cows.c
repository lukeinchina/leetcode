#include <stdio.h>
#include <stdlib.h>

char * getHint(char * secret, char * guess){
    int i, n, m;
    char *p = secret;
    char *q = guess;
    char *buff = (char *)malloc(16);
    int dict[10] = {0};
    int map[10]  = {0};
    m = n = 0;

    while ('\0' != *p && '\0' != *q) {
        if (*p == *q) {
            n++;
        } else {
            dict[*q - '0'] += 1;
            map[*p - '0'] += 1;
        }
        q++;
        p++;
    }
    for (i = 0; i < sizeof(dict) / sizeof(dict[0]); i++) {
        m += (dict[i] > map[i] ? map[i] : dict[i]);
    }

    snprintf(buff, 16, "%dA%dB", n, m);
    return buff;
}

int
main(int argc, char *argv[]) {
    char *p = NULL;
    if (argc < 3) {
        printf("usage:%s bulls cows\n", argv[0]);
        return 1;
    }
    p = getHint(argv[1], argv[2]);
    if (NULL != p) {
        printf("%s\n", p);
        free(p);
    }
    return 0;
}
