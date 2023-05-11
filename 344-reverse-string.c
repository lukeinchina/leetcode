#include <stdio.h>

void reverseString(char* s, int sSize){
    int i = 0;
    int j = sSize-1;
    char ch;
    while(i < j) {
        ch = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = ch;
        i++;
        j--;
    }
}
