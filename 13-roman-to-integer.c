#include <stdio.h>

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

int romanToInt(char * s){
    const static char ones[4]  = {'I', 'X', 'C', 'M'};
    const static char fives[4] = {'V', 'L', 'D', ' '};
    const static char tens[4]  = {'X', 'C', 'M', ' '};
    const static int  bases[4] = {1, 10, 100, 1000};
    int i, idx, val;
    val = 0;
    for (idx = 3; idx >= 0; idx--) {
        for (i = 0; ones[idx] == *s; s++) {
            i++;
        }
        if (fives[idx] == *s) {
            s++;
            if (i > 0) {
                val += (5 - i) * bases[idx];
            } else {
                for (i = 0; ones[idx] == *s; s++) {
                    i++;
                }
                val += (5 + i) * bases[idx];
            }
        } else if (tens[idx] == *s) {
            s++;
            val += (10 - i) * bases[idx];
        } else {
            val += i * bases[idx];
        }
    }
    return val;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s int\n", argv[0]);
        return -1;
    }
    printf("%s -> %d\n", argv[1], romanToInt(argv[1]));
    return 0;
}
