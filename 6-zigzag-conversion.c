#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * convert(char * s, int numRows){
    int step, row, i, idx, zigidx;
    int   len = strlen(s);
    char *dst = (char *)malloc(len+1);
    dst[len] = '\0';
    step = numRows + numRows - 2;
    idx  = 0;
    for (row = 0; row < numRows; row++) {
        zigidx = step - 2 * row; 
        for (i = row; i < len; i += step) {
            dst[idx++] = s[i];
            if (zigidx > 0 && zigidx < step && i+zigidx < len) {
                dst[idx++] = s[i + zigidx];
            }    
        }
    }
    return dst;
}

int
main(int argc, char *argv[]) {
    char *dst = NULL;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    dst =  convert(argv[1], 3);
    printf("%s -> substring:%s\n", argv[1], dst);

    return 0;
}
