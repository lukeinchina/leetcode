#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

string decodeString(string str) {
    const char *s = str.c_str();
    string dst;
    stack<int>  times;
    stack<char> brackets;

    while ('\0' != *s) {
        while (isalpha(*s)) {
            dst.append(1u, *s);
            s++;
        }
        int n = 0;
        while (isdigit(*s)) {
            ;
        }
    }
}
