
int isBadVersion(int version);

int firstBadVersion(int n) {
    int begin, mid, end = n-1;
    begin = 0;
    while (begin < end) {
        mid = begin +((end - begin ) >> 1);
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return end;
}
