#include <stdio.h>
#include <limits.h>

#define MAX_INT_VALUE 0X0FFFFFFFFFFFFFFFLL

bool helper(long a, long b, const char *s) {
    for (long c = 0; '\0' != *s; s++) {
        c = c * 10 + (*s - '0');
        if (c > a + b || c > MAX_INT_VALUE) {
            return false;
        } else if(c == a + b) {
            return '\0' == *(s+1) || helper(b, c, s+1);
        }
        if (0 == c) {
            break;
        }
    } 

    return false;
}

bool isAdditiveNumber(char * num){
    long a, b;
    const char *pb = NULL;
    for (a = 0;  a <= MAX_INT_VALUE && '\0' != *num; num++) {
        a  = a * 10 + (*num - '0');
        b  = 0;
        for (pb = num + 1; '\0' != *pb && b <= MAX_INT_VALUE; pb++) {
            b = b * 10 + (*pb - '0');

            /* 找到一个解 */
            if (helper(a, b, pb+1)) {
                printf("[%ld, %ld]\n", a, b);
                return true;
            }
            /* 只可能有一个0 */
            if (0 == b) {
                break;
            }
        }
        /* 只可能有一个0 */
        if (0 == a) {
            break;
        }
    }
    return false;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s number\n", argv[0]);
        return -1;
    }
    printf("%d\n", isAdditiveNumber(argv[1]));
    return 0;
}
