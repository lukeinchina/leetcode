#include <stdio.h>

int addDigits(int num){
    int val = 0;
    while (num > 9) {
        val = 0;
        while (num > 0) {
            val += num % 10;
            num /= 10;
        }
        num = val;
    }
    return num;
}
