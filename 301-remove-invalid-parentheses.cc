#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int valid_count(const string &s) {
    int count = 0;
    const char *p = s.c_str();
    const char *end   = s.c_str() + s.length();
    vector<char> ch;
    for (; p < end; p++) {
        if (*p >= 'a' && *p <= 'z') {
            continue;
        }else if (!ch.empty() && '(' == ch.back() && ')' == *p) {
            count++;
            ch.pop_back();
        } else {
            ch.push_back(*p);
        }
    }

    return count;
}

/* duplicate */
void append_result(const char *str, vector<string> &strs) {
    for (size_t i = 0; i < strs.size(); i++) {
        if (0 == strcmp(strs[i].c_str(), str)) {
            return;
        }
    }
    strs.push_back(str);
}

void select_valid(const char *s, int ln, int rn, int n, 
        char *stack, int top, vector<string> &strs) {
    if ('\0' == *s) {
        if (ln == rn && n == rn) {
            stack[top] = '\0';
            append_result(stack, strs);
        }
        return;
    } else if (ln < rn) {
        return;
    }

    stack[top] = *s;
    if ('(' == *s) {
        select_valid(s+1, ln+1, rn, n, stack, top+1, strs);
        select_valid(s+1, ln, rn, n, stack, top, strs);
    } else if (')' == *s) {
        select_valid(s+1, ln, rn+1, n, stack, top+1, strs);
        select_valid(s+1, ln, rn, n, stack, top, strs);
    } else {
        select_valid(s+1, ln, rn, n, stack, top+1, strs);
    }
}

vector<string> removeInvalidParentheses(string s) {
    int n = valid_count(s);
    char stack[64];
    vector<string> strs;
    select_valid(s.c_str(), 0, 0, n, stack, 0, strs);
    return strs;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    vector<string> strs =  removeInvalidParentheses(argv[1]);
    for (size_t i = 0; i < strs.size(); i++) {
        printf("%s\n", strs[i].c_str());
    }
    return 0;
}
