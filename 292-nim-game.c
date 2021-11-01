#include <stdio.h>
#include <stdlib.h>

bool canWinNim(int n){
    return n % 4 != 0;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return 0;
    }
    printf("%s\n", canWinNim(atoi(argv[1])) ? "true" : "false");
    return 0;
}
