#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <limits.h>

bool isPalindrome(int x){
    int i, j;
    int d[32];
    if (x < 0) {
        return false;
    }
    for (i = j = 0; x > 0; x /= 10) {
        d[j++] = x % 10;
    }
    
    while (j > i) {
        if (d[i] != d[j-1]) {
            return false;
        }
        j--;
        i++;
    }
    return true;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s int\n", argv[0]);
        return -1;
    }

    printf("%s atoi  %d\n", argv[1], isPalindrome(atoi(argv[1])));

    return 0;
}
