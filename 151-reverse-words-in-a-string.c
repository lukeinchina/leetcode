#include <ctype.h>
#include <string.h>

void reverse(char *begin, char *end) {
    char c;
    while (begin < end) {
        c      = *begin;
        *begin = *end;
        *end   = c;

        begin++;
        end--;
    }
}

char *trim(char *s) {
    char *p, *q;

    q = p = s;
    while ('\0' != *q) {
        /* skip space */
        while ('\0' != *q && isspace(*q)) {
            q++;
        }
        if (p != s && '\0' != *q) {
            *p++ = ' ';
        }
        /* copy word */
        while ('\0' != *q && !isspace(*q)){
            *p++ = *q++;
        }
    }
    *p = '\0';

    return s;
}

char * 
reverseWords(char * s){
    int  len = strlen(trim(s));
    char *p, *head = s;

    reverse(s, s+len-1);
    while ('\0' != *s) {
        p = s;
        while ('\0' != *p && !isspace(*p)) {
            p++;
        }
        reverse(s, p-1);
        while ('\0' != *p && isspace(*p)) {
            p++;
        }
        s = p;
    }
    return head;
}
