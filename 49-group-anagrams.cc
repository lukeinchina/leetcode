#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

void group_in_bucket(const vector<string> &strs, const vector<int> &idxes,
        vector<vector<string> > &results) {
    int size = idxes.size();
    vector<int> finished(size, 0);
    const char *p     = NULL;
    int dict[26], hash[26];
    for (int i = 0; i < size; i++) {
        if (finished[i] == 1) {
            continue;
        }
        vector<string> vec;
        vec.push_back(strs[idxes[i]]);
        results.push_back(vec);
        finished[i] = 1;

        memset(dict, 0, sizeof(dict));
        for (p = strs[idxes[i]].c_str(); '\0' != *p; p++) {
            dict[*p - 'a'] += 1;
        }
        for (int j = i+1; j < size; j++) {
            if (finished[j] == 1) {
                continue;
            }
            memset(hash, 0, sizeof(hash));
            for (p = strs[idxes[j]].c_str(); '\0' != *p; p++) {
                hash[*p - 'a'] += 1;
            }
            if (memcmp(dict, hash, sizeof(dict)) == 0) {
                finished[j] = 1;
                results[results.size() - 1].push_back(strs[idxes[j]]);
            }
        }
    }
    return ;
}
vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > results;
    size_t size = strs.size();
    map<int, vector<int> > buckets;
    map<int, vector<int> >::iterator it;
    for (int i = 0; i < size; i++) {
        it = buckets.find(strs[i].size());
        if (it != buckets.end()) {
            it->second.push_back(i);
        } else {
            vector<int> idxes;
            idxes.push_back(i);
            buckets.insert(pair<int, vector<int> >(strs[i].size(), idxes));
        }
    }
    for (it = buckets.begin(); it != buckets.end(); it++) {
        group_in_bucket(strs, buckets[it->first], results);
    }
    return results;
}

int
main(void) {
    size_t i;
    const char *strs[] = {"eat","tea","tan","ate","nat","bat", "hello", "world", "a"};
    // const char *strs[] = {""};
    vector<string> vec;
    for (i = 0; i < sizeof(strs) / sizeof(strs[0]); i++) {
        vec.push_back(strs[i]);
    }
    vector<vector<string> > results = groupAnagrams(vec);
    for (i = 0; i < results.size(); i++) {
        printf("[");
        for (size_t j = 0; j < results[i].size(); j++) {
            printf("%s,", results[i][j].c_str());
        }
        printf("]\n");
    }
    return 0;
}
