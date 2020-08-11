#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char * s){
    /* strlen(s) / 2 + 1长度即可以，可以判断提前结束.*/
    char *bottom = (char *)malloc(strlen(s)+1);
    char *top = bottom;
    for (; '\0' != *s; s++) {
        if ('{' == *s || '[' == *s || '(' == *s) {
            *top++ = *s;
            continue;
        }

        if (top == bottom) {
            free(bottom);
            return false;
        }
        top--;

        if ((']' == *s && *top != '[') 
                || ('}' == *s && *top != '{')
                || (')' == *s && *top != '(')) {
            free(bottom);
            return false;
        }
    }

    return top == bottom;
}

int main(void) {
    printf("%d\n", isValid("(-)({})"));
    return 0;
}
