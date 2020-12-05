#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
    int i,next;
    int prev = 1;
    int curr = 2;
    if (n < 3) {
        return n;
    }
    for (i = 2; i < n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
