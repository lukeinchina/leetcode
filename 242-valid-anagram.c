#include <stdio.h>
#include <string.h>

void count_freq(const char *s, int *dict) {
    for (; '\0' != *s; s++) {
        dict[*s - 'a'] += 1;
    }
}

bool isAnagram(char * s, char * t){
    int dict[26] = {0};
    int map[26]  = {0};

    count_freq(s, dict);
    count_freq(t, map);
    return (memcmp(dict, map, sizeof(dict)) == 0);
}
