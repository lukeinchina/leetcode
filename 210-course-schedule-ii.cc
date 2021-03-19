#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int v;
    struct ListNode *next;
};

typedef struct {
    struct ListNode **vertex;
    int size;
}AdjTable;

void init_table(AdjTable *table, int n) {
    table->size = n;
    table->vertex = (struct ListNode **)calloc(n, sizeof(struct ListNode *));
}

void uninit_table(AdjTable *table) {
    struct ListNode *p, *q;
    int i;
    for (i = 0; i < table->size; i++) {
        p = table->vertex[i];
        while (NULL != p) {
            q = p;
            p = p->next;
            free(q);
        }
        table->vertex[i] = NULL;
    }
    free(table->vertex);
    table->size = 0;
    return;
}

void add_edge(AdjTable *table, int start, int end) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->v = end;
    p->next = table->vertex[start];
    table->vertex[start] = p;
}

int remove_edge(AdjTable *table, int v, int *end) {
    struct ListNode *p = table->vertex[v];
    if (NULL == p) {
        return -1;
    }
    *end = p->v;
    table->vertex[v] = p->next;
    free(p);
    return 0;
}

bool has_edge(const AdjTable *table) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (NULL != table->vertex[i]) {
            return false;
        }
    }
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
    size_t i;
    int *in = (int *)calloc(numCourses, sizeof(int));
    queue<int> zero_in;
    vector<int> path;

    AdjTable table = {NULL, 0};
    init_table(&table, numCourses);
    
    size_t nedge =  prerequisites.size();
    for (i = 0; i < nedge; i++) {
        add_edge(&table, prerequisites[i][1], prerequisites[i][0]);
        in[prerequisites[i][0]] += 1;
    }
    for (i = 0; i < (size_t)numCourses; i++) {
        if (in[i] == 0) {
            zero_in.push(i);
            path.push_back(i);
        }
    }

    while (!zero_in.empty()) {
        int ve;
        int v = zero_in.front();
        zero_in.pop();
        while (remove_edge(&table, v, &ve) == 0) {
            in[ve] -= 1;
            if (0 == in[ve]) {
                zero_in.push(ve);
                path.push_back(ve);
            }
        }
    }
    bool can = has_edge(&table);

    uninit_table(&table);
    free(in);
    if (can) {
        path.clear();
    }
    return path;
}

int
main(void) {
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    vector<int> b;
    b.push_back(0);
    b.push_back(1);

    vector<vector<int> > prep;
    prep.push_back(a);
    prep.push_back(b);
    vector<int> path =  findOrder(2, prep);
    return 0;
}
