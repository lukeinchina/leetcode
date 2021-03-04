#include <string.h>

int titleToNumber(char * s){
    int n = 0;
    for (; '\0' != *s; s++) {
        n *= 26;
        n += (*s - 'A') + 1;
    }
    return n;
}
