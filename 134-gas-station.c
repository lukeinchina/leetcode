#include <stdio.h>
#include <stdlib.h>

int dfs(int* gas, int* cost, int size, int index, int visited[], int left) {
    left += gas[index % size] - cost[index % size];
    if (left < 0) {
        return 0;
    } else if (visited[index % size]) {
        return 1;
    }

    visited[index % size] = 1;
    if (dfs(gas, cost, size, index+1, visited, left)) {
        return 1;
    }
    visited[index % size] = 0;

    return 0;
}

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int i, j, left;
    for (i = 0; i < gasSize; i++) {
        for (left = j = 0; j < gasSize; j++) {
            left += gas[(i+j) % gasSize] - cost[(i+j) % gasSize];
            if (left < 0) {
                break;
            }
        }
        if (left >= 0) {
            return i;
        }
    }
    return -1;
}

int
main(void) {
    int gas[]  = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int index = canCompleteCircuit(gas, sizeof(gas)/sizeof(gas[0]), cost, sizeof(cost)/sizeof(cost[0]));
    printf("%d\n", index);
    return 0;
}
