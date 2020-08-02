#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome_len(const char *s, int len, int l, int r, int *pos) {
    int size = 0;
    while (l >= 0 && r < len && s[l] == s[r]) {
        size = r - l + 1;
        *pos = l;
        l--;
        r++;
    }
    return size;
}

char * longestPalindrome(char * s){
    int len = strlen(s);
    int i, max, pos, size, begin;
    char *dst = NULL;
    max = 0;
    for (i = 0; i < len; i++) {
        size = palindrome_len(s, len, i, i, &pos);
        if (size > max) {
            max = size;
            begin = pos;
        }
        size = palindrome_len(s, len, i, i+1, &pos);
        if (size > max) {
            max = size;
            begin = pos;
        }
    }
    dst = (char *)malloc(max + 1);
    dst[max] = '\0';
    if (max > 0) {
        memcpy(dst, s + begin, max);
    }
    return dst;
}

int
main(int argc, char *argv[]) {
    char *dst = NULL;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    dst =  longestPalindrome(argv[1]);
    printf("%s -> substring:%s\n", argv[1], dst);

    return 0;
}
