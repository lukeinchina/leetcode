#include <string.h>
#include <stdio.h>

int StringSplit(char* str ) {
    // write code here
    char *p = str;
    int n1 = (*p == 'a') ? 1 : 0;
    int i, j, n2 = 0;
    int max = 0;
    for(p++; '\0' != *p; p++){
        if ('b' == *p) {
            n2++;
        }
    }
    max = n1 + n2;
    for (str += 1; str+1 < p; str++){
        if ('a' == *str) {
            n1++;
        }else if ('b' == *str) {
            n2--;
        }
        if (n1 + n2 > max) {
            max = n1 + n2;
        }
    }
    return max;
 }

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        return -1;
    }
    printf("%d\n", StringSplit(argv[1]));
    return 0;
}
