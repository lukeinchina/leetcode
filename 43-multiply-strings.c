#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * multiply(char * num1, char * num2){
    int i, j, k;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total = len1+len2;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s num1 num2\n", argv[0]);
        return -1;
    }

    printf("%s\n", multiply(argv[1], argv[2]));
    return 0;
}
