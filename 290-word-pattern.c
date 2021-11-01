#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool cmp_until_space(const char *p, const char *s) {
    while ('\0' != *p && '\0' != *s && !isspace(*p) && !isspace(*s) && *p == *s) {
        p++;
        s++;
    }
    return (*p == *s || ('\0' == *p && ' ' == *s) || (' ' == *p && '\0' == *s));
}

char *next_word(char *s) {
    while ('\0' != *s && ' ' != *s) {
        s++;
    }
    if ('\0' != *s && ' ' == *s) {
        s++;
    }
    return s;
}


bool wordPattern(char * pattern, char * s){
    char *p = pattern;
    char *q = s;
    int finish[26] = {0};

    for (; '\0' != *pattern && '\0' != *s; pattern++, s = next_word(s)) {
        if (('\0' == *pattern && '\0' != *s) || ('\0' != *pattern && '\0' == *s)) {
            return false;
        }
        if (finish[*pattern - 'a']) {
            continue;
        }
        finish[*pattern - 'a'] = 1;

        q = next_word(s);
        for (p = pattern + 1; '\0' != *p; p++) {
            if ((*pattern == *p) != cmp_until_space(s, q)) {
                return false;
            }
            q = next_word(q);
        }
    }

    return '\0' == *pattern && '\0' == *s;
}

int main(void) {
    char pat[] = {"abba"};
    char text[] = {"dog cat cat dog"};

    printf("match:%d, [%s] [%s]\n", wordPattern(pat, text), pat, text);
    return 0;
}
