#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

bool isHappy(int n){
    int nums[16];
    int i, size;
    set<int> exist;

    while (exist.count(n) < 1 && n != 1) {
        exist.insert(n);

        size = 0;
        for (; n != 0; n /= 10) {
            nums[size++] = n % 10;
        }
        n = 0;
        for (i = 0; i < size; i++) {
            n += nums[i] * nums[i];
        }
    }
    return (n == 1);
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    bool ans = isHappy(atoi(argv[1]));
    if (ans) {
        printf("happy\n");
    }
    return 0;
}
