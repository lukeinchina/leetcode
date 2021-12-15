#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>
#include <map>

using namespace std;

int max_height(const vector<vector<int> > &tbl, int root, vector<int> &visited) {
    int v, height, max = 0;
    visited[root] = 1;
    for (size_t i = 0; i < tbl[root].size(); i++) {
        v = tbl[root][i];
        if (visited[v]) {
            continue;
        }
        height = max_height(tbl, v, visited);
        max = (height > max ? height : max);
    }
    visited[root] = 0;
    return max + 1;
}

vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
    int i, h, nedge = edges.size();
    int root     = n / 2;

    vector<int> vtx;
    vector<vector<int> > adjtbl(n);
    vector<int> visited(n);

    for (i = 0; i < nedge; i++) {
        adjtbl[edges[i][0]].push_back(edges[i][1]);
        adjtbl[edges[i][1]].push_back(edges[i][0]);
    }

    while (root >= 0) {
        int nchild = adjtbl[root].size();
        int smax, max, v  = -1;
        smax = max = 0;
        visited[root] = 1;
        for (i = 0; i < nchild; i++) {
            h = max_height(adjtbl, adjtbl[root][i], visited);
            if (h > max) {
                v    = adjtbl[root][i];
                smax = max;
                max  = h;
            } else if (h > smax) {
                smax = h;
            }
        }
        if (max == smax) {
            vtx.push_back(root);
            break;
        } else if (smax+1 == max) {
            vtx.push_back(root);
            vtx.push_back(v);
            break;
        }

        visited[root] = 0;
        root = v;
    }
    return vtx;
}


int
main(void) {
    // int matrix[][2] = {{0,1},{0,2},{0,3},{3,4},{3,5},{1,6},{4,7},{2,8},{0,9},{0,10},{2,11}};
    int matrix[][2] = {{0,1},{1,2},{1,3},{2,4},{3,5},{4,6}};
    // vector<vector<int> >edges(sizeof(matrix) / sizeof(matrix[0]));
    int n = sizeof(matrix) / sizeof(matrix[0]) + 1;
    vector<vector<int> >edges(n-1);
    for (int i = 0; i < edges.size(); i++) {
        edges[i].push_back(matrix[i][0]);
        edges[i].push_back(matrix[i][1]);
    }
    vector<int >roots = findMinHeightTrees(n, edges);
    for (int i = 0; i < roots.size(); i++) {
        printf("%d%c", roots[i], i+1 == roots.size() ? '\n' : '\t');
    }
    return 0;
}
