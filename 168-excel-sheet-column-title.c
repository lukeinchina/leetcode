#include <stdio.h>
#include <stdlib.h>

char * convertToTitle(int n){
//    static char *dict = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c, *buf = (char*)malloc(16);
    int i, end = 0;
    while (n > 0) {
        n -= 1;
        buf[end++] = 'A' + (n % 26);
        n /= 26;
    }
    buf[end] = '\0';
    end -= 1;
    i = 0;
    while (i < end) {
        c = buf[i];
        buf[i] = buf[end];
        buf[end] = c;
        i++;
        end--;
    }
    printf("%s\n", buf);
    return buf;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%s\n", convertToTitle(atoi(argv[1])));
    return 0;
}
