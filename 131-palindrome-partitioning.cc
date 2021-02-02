#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int is_palindrome(const char *begin, const char *end) {
    while (begin < end) {
        if (*begin++ != *end--) {
            return 0;
        }
    }
    return 1;
}

void helper(const char *s, int begin, int end, vector<vector<string> > &rst, int top) {
    size_t i, j, size;
    if (begin == end) {
        vector<string> a;
        a.push_back(string(s+begin, 1));
        rst.push_back(a);
        return ;
    }

    helper(s, begin, end-1, rst, top);

    /* 最后一个字符补上 */
    size = rst.size();
    for (i = top; i < size; i++) {
        rst[i].push_back(string(s+end, 1));
    }

    /* 最后一个字符可能形成的回文串. */
    for (i = begin; i < end; i++) {
        if (!is_palindrome(s+i, s+end)) {
            continue;
        }
        string a(string(s+i, end+1-i));
        if (i == begin) {
            vector<string> one;
            one.push_back(a);
            rst.push_back(one);
            continue;
        } 
        
        size = rst.size();
        helper(s, begin, i-1, rst, size);

        for (j = size; j < rst.size(); j++) {
            rst[j].push_back(a);
        }
    }
}

vector<vector<string> > partition(string s) {
     vector<vector<string> >   rst;
     helper(s.c_str(), 0, s.size()-1, rst, 0);
     return rst;
}

int
main(int argc, char *argv[]) {
    size_t i, j, size;
    if (argc < 2) {
        printf("usage:%s str\n", argv[0]);
        return -1;
    }
    vector<vector<string> > all = partition(argv[1]);
    printf("[\n");
    for (i = 0; i < all.size(); i++) {
        printf("[");
        size = all[i].size();
        for (j = 0; j < size; j++) {
            printf("%s%c", all[i][j].c_str(), j+1== size ? ' ' : ',');
        }
        printf("]\n");
    }
    printf("]\n");
    return 0;
}
