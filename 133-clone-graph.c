#include <stdio.h>
#include <stdlib.h>

 struct Node {
     int val;
     int numNeighbors;
     struct Node** neighbors;
 };

struct Node *dfs(const struct Node *s, void * visited[]) {
    int i;
    struct Node *t;
    if (NULL == s ) {
        return NULL;
    } else if(NULL != visited[s->val]) {
        return visited[s->val];
    }
    /* copy */

    t               = (struct Node *)malloc(sizeof(struct Node));
    t->val          = s->val;
    t->numNeighbors = s->numNeighbors;
    t->neighbors    = (struct Node **)malloc(sizeof(struct Node *) * s->numNeighbors);
    visited[s->val] = t;

    for (i = 0; i < s->numNeighbors; i++) {
        t->neighbors[i] = dfs(s->neighbors[i], visited);
    }
    return t;
}

struct Node *cloneGraph(struct Node *s) {
    void * visited[100] = {NULL};
    return dfs(s, visited);
}

void print_graph(const struct Node *s, int visited[]) {
    int i;
    struct Node *t;
    if (NULL == s || visited[s->val]) {
        return ;
    }
    /* copy */
    visited[s->val] = 1;

    printf("[%d]:[", s->val);
    for (i = 0; i < s->numNeighbors; i++) {
        t = s->neighbors[i];
        printf("%d", t->val);
        if (i+1 != s->numNeighbors) {
            printf(" ");
        }
    }
    printf("]\n");
    for (i = 0; i < s->numNeighbors; i++) {
        t = s->neighbors[i];
        print_graph(t, visited);
    }
    return ;
}

int
main(void) {
    struct Node *t;
    int visited[100] = {0};

    struct Node *an[2] = {NULL, NULL};
    struct Node *bn[2] = {NULL, NULL};
    struct Node *cn[2] = {NULL, NULL};
    struct Node *dn[2] = {NULL, NULL};

    struct Node a = {1, 2, an};
    struct Node b = {2, 2, bn};
    struct Node c = {3, 2, cn};
    struct Node d = {4, 2, dn};

    a.neighbors[0] = &b;
    a.neighbors[1] = &d;

    b.neighbors[0] = &a;
    b.neighbors[1] = &c;

    c.neighbors[0] = &b;
    c.neighbors[1] = &d;

    d.neighbors[0] = &a;
    d.neighbors[1] = &c;
    
    t = cloneGraph(&a);
    print_graph(t, visited);
    printf("\n");

    return 0;
}
