#include <stdlib.h>

#include "adj_table.h"

void adj_table_create(AdjTable &table, int size) {
    table.size = size;
    table.vtx  = (Vertex *)calloc(size, sizeof(struct Vertex));
}

void adj_table_destroy(AdjTable &table) {
    for (int i = 0; i < table.size; i++) {
        if (NULL == table.vtx[i].edge) {
            continue;
        }
        free(table.vtx[i].edge);
        table.vtx[i].edge = NULL;
    }
    free(table.vtx);
    table.vtx  = NULL;
    table.size = 0;
}
