#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>

#include "adj_table.h"

#define MAX_EDGE 10
#define MAX_DIST 100


using namespace std;

struct Point {
    int id;
    int x;
    int y;
};

inline void parse_point(const char *line, Point &point) {
    int nums[3] = {0};
    for (int i = 0; i < 3 && '\0' != *line; i++) {
        nums[i] = atoi(line);
        while( '\0' != *line && ',' != *line) {
            line++;
        } 
        if (',' == *line) {
            line++;
        }
    }
    point.id = nums[0];
    point.x  = nums[1];
    point.y  = nums[2];
}

int read_points(FILE *fp, vector<Point> &points) {
    int count;
    char line[32];
    fgets(line, sizeof(line), fp);
    count = atoi(line);
    points.resize(count);
    for (int i = 0; i < count; i++) {
        fgets(line, sizeof(line), fp);
        parse_point(line, points[i]);
    }
    return count;
}

void print_input(const vector<Point> &tasks, const vector<Point> &workers) {
    size_t i;
    printf("%lu\n", tasks.size());
    for (i = 0; i < tasks.size(); i++) {
        const Point &point = tasks[i];
        printf("%d,%d,%d\n", point.id, point.x, point.y);
    }
    printf("%lu\n", workers.size());
    for (i = 0; i < workers.size(); i++) {
        const Point &point = workers[i];
        printf("%d,%d,%d\n", point.id, point.x, point.y);
    }
}

int 
read_input(const char *path, vector<Point> &tasks, vector<Point> &workers) {
    FILE *fp = fopen(path, "r");
    if (NULL == fp) {
        return -1;
    }
    read_points(fp, tasks);
    read_points(fp, workers);
    fclose(fp);
    return 0;
}

Edge * 
get_near_vtx(const Point &start, const vector<Point> &points, int &count) {
    int i, x, y, dist, size = points.size();
    priority_queue<Edge> max_heap;
    x = start.x;
    y = start.y;
    Edge e;
    for (i = 0; i < size; i++) {
        if (points[i].id == start.id) {
            continue;
        }
        dist  = (x > points[i].x ? x - points[i].x : points[i].x - x);
        dist += (y > points[i].y ? y - points[i].y : points[i].y - y);
        e.id     = points[i].id;
        e.dist   = dist;

        if (max_heap.size() < MAX_EDGE) {
            max_heap.push(e);
            continue;
        } 

        Edge max = max_heap.top();
        if (e.dist < max.dist) {
            max_heap.pop();
            max_heap.push(e);
        }
    }

    count = max_heap.size();
    Edge *p = (Edge *)malloc(size * sizeof(struct Edge));
    for (i = count - 1; i >= 0; i--) {
        e = max_heap.top();
        max_heap.pop();
        p[i].id   = e.id;
        p[i].dist = e.dist;
    }

    return p;
}

void print_one_vertex(const AdjTable &graph, int id) {
    printf("vertex:%d-->[", id);
    for (int i = 0; i < graph.vtx[id-1].count; i++) {
        Edge e = graph.vtx[id-1].edge[i];
        printf("(%d:%d)", e.id, e.dist);
    }
    printf("]\n");
}

int create_graph(AdjTable &graph, const vector<Point> &points) {
    int count, size = points.size();
    for (int i = 0; i < size; i++) {
        int id = points[i].id;

        graph.vtx[id-1].edge  = get_near_vtx(points[i], points, count);
        graph.vtx[id-1].id    = id;
        graph.vtx[id-1].count = count;
    }
//     print_one_vertex(graph, points[10].id);
    return 0;
}

void create_seeds(const vector<Point> &tasks, const vector<Point> &workers, 
        vector<Vertex> &seeds) {
    int count = 0;
    seeds.resize(workers.size());
    for (size_t i = 0; i < workers.size(); i++) {
        Point start = workers[i];
        start.id    = -1; /* 标记区分 */
        seeds[i].edge  = get_near_vtx(start, workers, count);
        seeds[i].count = count;
        seeds[i].id    = workers[i].id;
    }
}

void print_solution(const int *paths, int size, int total) {
    printf("count:%d [", size);
    for (int i = 0; i < size; i++) {
        printf("%d%c", paths[i], i+1 == size ? ']' : ',');
    }
    printf(" total:%d\n", total);
}

void greedy_dispatch(const AdjTable &graph, int id, 
        vector<int> &visited, int paths[], int top, int total) {
    for (int i = 0; i < graph.vtx[id-1].count; i++) {
        Edge e = graph.vtx[id-1].edge[i];
        if (visited[e.id-1]) {
            continue;
        }
        if (total + e.dist > MAX_DIST) {
            print_solution(paths, top, total);
            return ;
        } else if (total + e.dist == MAX_DIST) {
            paths[top++] = e.id;
            print_solution(paths, top, total);
            return ;
        }
        paths[top]      = e.id;
        visited[e.id-1] = 1;
        greedy_dispatch(graph, e.id, visited, paths, top+1, total+e.dist);
        visited[e.id-1] = 0;
        return ;
    }
}

void greedy_dispatch(const AdjTable &graph, const vector<Vertex> &seeds) {
    int paths[MAX_DIST]   = {0};
    vector<int> visited(graph.size, 0);

    for (size_t i = 0; i < seeds.size(); i++) {
        Edge *array = seeds[i].edge;
        if (seeds[i].count < 1 || array[0].dist > MAX_DIST) {
            printf("%d hasn't near nodes\n", seeds[i].id);
            continue;
        }
        visited[array[0].id-1] = 1;
        paths[0] = array[0].id;
        greedy_dispatch(graph, array[0].id, visited, paths, 1, array[0].dist);
        visited[array[0].id-1] = 1;
    }
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s input\n", argv[0]);
        return -1;
    }
    vector<Point> tasks;
    vector<Point> workers;
    read_input(argv[1], tasks, workers);

    vector<Vertex> seeds;
    create_seeds(tasks, workers, seeds);


    struct AdjTable graph = {NULL, 0};
    adj_table_create(graph, tasks.size());
    create_graph(graph, tasks);

    greedy_dispatch(graph, seeds);

    adj_table_destroy(graph);

    return 0;
}
