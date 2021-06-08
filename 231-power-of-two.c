#include <stdio.h>

bool isPowerOfTwo(int n){
    if (0 == (n&(n-1))) {
        return true;
    }
    return false;
}

