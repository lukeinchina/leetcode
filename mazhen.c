#include <stdio.h>
#include <stdlib.h>

int calculateExtraNum(int totalNum, int exchangeNum ) {
    // write code here
    int total = 0;
    int n = totalNum / exchangeNum; 
    int r = totalNum % exchangeNum;
    total += n;
    while (n+r >= 3) {
        n += r;
        n /= exchangeNum;
        r = n % exchangeNum;
        total += n;
    }
    return total;
}

int
main(int argc, char *argv[]) {
    int a, b;
    if (argc < 3) {
        return -1;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%d\n", calculateExtraNum(a, b));
    return 0;
}
