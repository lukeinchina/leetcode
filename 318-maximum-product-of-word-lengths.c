#include <stdio.h>
#include <string.h>

void fill_set(char *set, const char *s) {
    while ('\0' != *s) {
        set[*s++ - 'a'] = 1;
    }
}

int maxProduct(char ** words, int wordsSize){
    int i, j;
    int len, mul = 0, max = 0;
    char set[26], *p;
    for (i = 0; i < wordsSize; i++) {
        memset(set, 0, sizeof(set));
        fill_set(set, words[i]);
        len = strlen(words[i]);

        for (j = i+1; j < wordsSize; j++) {
            for (p = words[j]; '\0' != *p; p++) {
                if (set[*p - 'a']) {
                    break;
                }
            }
            mul = ('\0' == *p ? len * (p - words[j]) : 0);
            max = mul > max ? mul : max;
        }
    }
    return max;
}

int
main(void) {
    char *words[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
    printf("%d\n", maxProduct(words, sizeof(words) / sizeof(words[0])));
    return 0;
}
