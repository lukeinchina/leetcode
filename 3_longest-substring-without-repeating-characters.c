#include <stdio.h>
#include <string.h>

int 
lengthOfLongestSubstring(const char * s){
    const static int MAP_SIZE = 256;
    const char *p = s;
    const char *q;
    char map[MAP_SIZE];
    int max = 0;
    for (; '\0' != *p; p++) {
        memset(map, 0, sizeof(char) * MAP_SIZE);
        for (q = p; '\0' != *q; q++) {
            if (map[*q] != 0) {
                break;
            } 
            max = (q - p + 1 > max) ? (q - p + 1) : max;
            map[*q] = 1;
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage %s string\n", argv[0]);
        return 1;
    }
    printf("max len : %d\n", lengthOfLongestSubstring(argv[1]));
    return 0;
}
