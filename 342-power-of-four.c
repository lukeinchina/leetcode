
bool isPowerOfFour(int n){
    while (n > 4) {
        if ((n & 0X03) != 0) {
            return false;
        }
        n >>= 2;
    }
    return n == 4;
}
