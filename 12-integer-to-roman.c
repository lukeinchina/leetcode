#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num){
    char *p = (char *)malloc(16);
    int i,idx,d,j;
    int digits[4];
    char ones[4]  = {'I', 'X', 'C', 'M'};
    char fives[4] = {'V', 'L', 'D', ' '};
    for (i = 0; num > 0; num /= 10) {
        digits[i++] = num % 10;
    }
    for (idx = 0; i > 0; i--) {
        d = digits[i-1];
        if (d == 0) {
            continue;
        } else if (d <= 3) {
            for (j = 0; j < d; j++) {
                p[idx++] = ones[i-1];
            }
        }else if (d == 4) {
            p[idx++] = ones[i-1];
            p[idx++] = fives[i-1];
        } else if (d == 5) {
            p[idx++] = fives[i-1];
        }else if (d <= 8) {
            p[idx++] = fives[i-1];
            for (j = 5; j < d; j++) {
                p[idx++] = ones[i-1];
            }
        }else { /* 9 */
            p[idx++] = ones[i-1];
            p[idx++] = ones[i];
        }
    }
    p[idx] = '\0';
    return p;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s int\n", argv[0]);
        return -1;
    }
    printf("%s -> %s\n", argv[1], intToRoman(atoi(argv[1])));
    return 0;
}
