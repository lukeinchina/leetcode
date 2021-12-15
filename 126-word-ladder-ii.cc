#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct AdjTable {
    struct ListNode *vertex;
    int size;
};

int diff(const char *s, const char *t) {
    int d = 0;
    while ('\0' != *s && '\0' != *t) {
        d += (*s++ != *t++);
    }
    return d;
}

void adj_table_init(struct AdjTable *table, int size) {
    table->size  = size;
    table->vertex = (struct ListNode *)calloc(size, sizeof(struct ListNode));
    return ;
}

void adj_table_destroy(struct AdjTable *table) {
    int i;
    struct ListNode *p;
    for (i = 0; i < table->size; i++) {
        for (p = table->vertex[i].next; NULL != p; p = table->vertex[i].next) {
            table->vertex[i].next = p->next;
            free(p);
        }
    }
    free(table->vertex);

    table->vertex = NULL;
    table->size   = 0;
}

int
adj_table_add(struct AdjTable *table, int begin, int end) {
    struct ListNode *p        = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val                    = end;
    p->next                   = table->vertex[begin].next;
    table->vertex[begin].next = p;
    return 0;
}



/* ------------------------------------------------- */
void make_path(int *vertex, int size, const vector<string> &word_list,
        vector<string> &path) {
    for (int i = 0; i < size; i++) {
        path.push_back(word_list[vertex[i]]);
    }
}

int bfs(const struct AdjTable *table, int begin, int end, 
        vector<vector<int> > &next_hops) {
    int v, got = 0;
    vector<int> visited(table->size, 0);
    vector<int> finished(table->size, 0);

    vector<int> vec1, vec2;
    vector<int> *curr, *next, *temp;
    curr = &vec1;
    next = &vec2;

    curr->push_back(end);
    visited[end]  = 1;
    finished[end] = 1;
    while (!curr->empty()) {
        while (!curr->empty()) {
            v = curr->back();
            curr->pop_back();
            if (v == begin) {
                got = 1;
            }

            for (ListNode *p = table->vertex[v].next; NULL != p; p = p->next) {
                /* 该节点路径都已经计算完了 */
                if (finished[p->val]) {
                    continue;
                }
                if (!got && !visited[p->val]) {
                    next->push_back(p->val);
                }
                visited[p->val] = 1;
                next_hops[p->val].push_back(v);
            }
        }

        for (int i = 0; i < next->size(); i++) {
            finished[next->at(i)] = 1;
        }
        /* swap */
        temp = curr;
        curr = next;
        next = temp;
    }
    return 0;
}

void dfs(vector<vector<int> > &next_hops, int begin, int end, 
        int stack[], int top, int max,
        const vector<string> &words, vector<vector<string> > &all_paths) {
    if (begin == end) {
        stack[top++] = end;
        all_paths.resize(all_paths.size() + 1);
        make_path(stack, top, words, all_paths[all_paths.size() - 1]);
        return ;
    }
    stack[top++] = begin;
    const vector<int> &vec = next_hops[begin];
    for (size_t i = 0; i < vec.size(); i++) {
        dfs(next_hops, vec[i], end, stack, top, max, words, all_paths);
    }

    return;
}

void get_all_paths(const AdjTable *table, int begin, int end, 
        const vector<string> &words, vector<vector<string> > &all_paths) {

    /* 当前节点V，以及V到目标的下一跳  */
    vector<vector<int> > nexts(table->size);
    int min = bfs(table, begin, end, nexts);
    
    int *stack   = (int *)calloc(words.size(), sizeof(int));
    dfs(nexts, begin, end, stack, 0, min, words, all_paths);
    free(stack);
    return;
}

vector<vector<string> > 
findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string> > all_paths;

    int i, j, begin, end, size = wordList.size();
    struct AdjTable table;
    begin = end = -1;

    for (i = 0; i < size; i++) {
        if (beginWord == wordList[i]) {
            begin = i;
        }
        if (wordList[i] == endWord) {
            end = i;
        }
    }

    /* 目标值不在 */
    if (end < 0) {
        return all_paths;
    }
    /* 起始词如不在list中，也加入其中 */
    if (begin < 0) {
        begin = wordList.size();
        wordList.push_back(beginWord);
        size  = wordList.size();
    }
    adj_table_init(&table, size);
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (1 != diff(wordList[i].c_str(), wordList[j].c_str())) {
                continue;
            }
            adj_table_add(&table, i, j);
            adj_table_add(&table, j, i);
        }
    }

    get_all_paths(&table, begin, end, wordList, all_paths);
    adj_table_destroy(&table);
    return all_paths;
}

int get_line_count(const char *path) {
    char line[1024];
    int count = 0;
    FILE *fp = fopen(path, "r");
    while (NULL != fgets(line, sizeof(line), fp)) {
        count += 1;
    }
    fclose(fp);
    return count;
}

char **
read_test_case(const char *path, int *count) {
    char **pp = NULL;
    char line[256];
    FILE *fp = NULL;
    int i = 0;
    int len;
    *count = get_line_count(path);
    if (*count <= 0) {
        return NULL;
    }
    pp = (char **)malloc(sizeof(char *) * *count);
    fp = fopen(path, "r");
    while (NULL != fgets(line, sizeof(line), fp)) {
        len = strlen(line);
        while (isspace(line[len-1])) {
            line[--len] = '\0';
        }
        pp[i++] = strdup(line);
    }
    fclose(fp);
    return pp;
}

int
main(int argc, char *argv[]) {
    int i, size;
    // char **strs = read_test_case("./case.txt", &size);
    const char *strs[] = {"hot","dot","dog","lot","log","cog"};
    size = sizeof(strs) / sizeof(strs[0]);
    if (argc < 3) {
        printf("usage:%s begin  end\n", argv[0]);
        return -1;
    }
    vector<string> word_list;
    for (int i = 0; i < size; i++) {
        word_list.push_back(string(strs[i]));
    }


    printf("input count:%d\n", size);
    vector<vector<string> > paths = findLadders(argv[1], argv[2], word_list);

    printf("totol paths:%lu\n", paths.size());

    for (i = 0; i < paths.size(); i++) {
        vector<string> &vec = paths[i];
        printf("[");
        for (int j = 0; j < vec.size(); j++) {
            printf("%s%c", vec[j].c_str(), j+1 == vec.size() ? ']' : ',');
        }
        printf("\n");
    }
    // printf("min path: %d\n", ladderLength(argv[1], argv[2], strs, size));
    return 0;
}
