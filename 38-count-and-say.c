#include <stdio.h>
#include <stdlib.h>

char * countAndSay(int n){
    int idx, count;
    static int sizes[] = {1, 32,32,32,32,32,32,32,32,32,32,\
                  128, 128, 128, 128, 256, 256, 256, 512, 512, 512, \
                  1024, 1024, 1024, 1024, 2048, 4096, 4096, 4096, 8192, 8192};
    char *dst = (char *)calloc(sizes[n], sizeof(char));
    char *tmp = (char *)calloc(sizes[n], sizeof(char));
    char *p, *q;
    dst[0] = '1';
    p = dst;
    q = tmp;
    for (idx = 2; idx <= n; idx++) {
        while ('\0' != *p) {
            for (count = 1; '\0' != *p && *p == *(p+1); p++) {
                count += 1;
            }
            *q = (count + '0'); /* 个数 */
            *(q+1) = *p;
            q += 2;
            p += 1;
        }

        /* 准备下一轮 */
        if (idx % 2) {
            p = dst;
            q = tmp;
        } else {
            p = tmp;
            q = dst;
        }
    }
    if (n % 2) {
        free(tmp);
        return dst;
    } else {
        free(dst);
        return tmp;
    }
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return 0;
    }
    printf("%s\n", countAndSay(atoi(argv[1])));
    return 0;
}
