#include <stdio.h>
#include <string.h>

char * reverseVowels(char * s){
    char t, map[128] = {0};
    char *l = s;
    char *r = s + strlen(s) - 1;
    map['a'] = map['e'] = map['i'] = map['o'] = map['u'] = 1;
    map['A'] = map['E'] = map['I'] = map['O'] = map['U'] = 1;
    while (l < r) {
        while (l < r && map[*l] != 1) {
            l++;
        }
        while (l < r && map[*r] != 1) {
            r--;
        }
        if (l < r) {
            t  = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    return s;
}
