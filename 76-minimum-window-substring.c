#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int check(const int *map, const int *wnds, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (map[i] > 0 && map[i] > wnds[i]) {
            return 0;
        }
    }
    return 1;
}

char * minWindow(char * s, char * t){
    const static int MAP_SIZE = 128;
    int map[MAP_SIZE]  = {0};
    int wnds[MAP_SIZE] = {0};
    int count, size;
    int min = INT_MAX;
    const char *begin, *curr, *end, *start;
    char c, *dst = NULL;

    memset(map, 0, sizeof(map));
    memset(wnds, 0, sizeof(wnds));
    start = NULL;
    count = size = 0;
    begin = curr = s;
    end   = s + strlen(s);

    for (; '\0' != *t; t++) {
        map[*t] += 1;
        size    += 1;
    }
    for (; curr < end; curr++) {
        c = *curr;

        if (map[c] > 0 && wnds[c]++ < map[c]) {
            count++;
        }
        /* 窗口左边位置向右滑动 */
        while (count == size && begin <= curr) {
            if (check(map, wnds, MAP_SIZE)) {
                if (min > (curr-begin+1)) {
                    min = curr - begin+1;
                    start = begin;
                }
            }
            c = *begin++;
            wnds[c] -= 1;
            if (map[c] > 0 &&  wnds[c] < map[c]) {
                count--;
            }
        }
    }
    if (NULL != start) {
        dst = (char *)malloc(min+1);
        strncpy(dst, start, min);
        dst[min] = '\0';
    }
    return dst;
}

int
main(int argc, char *argv[]) {
    char *p = NULL;
    if (argc < 3) {
        printf("usage:%s s t \n", argv[0]);
        return 0;
    }
    p = minWindow(argv[1], argv[2]);
    printf("%s\n", p);
    return 0;
}
