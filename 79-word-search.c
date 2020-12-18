#include <stdio.h>

bool exist(char** board, int boardSize, int* boardColSize, char * word){

}

int main(int argc, char *argv[]) {
    int array[][4] = {{1,3,5,7},  {10,11,16,20}, {23,30,34,50}};
    int *pp[] = {array[0], array[1], array[2]};
    int cols[] = {4, 4, 4};
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    print_array(pp, 3, 4);
    printf("%d\n", searchMatrix(pp, sizeof(pp)/sizeof(pp[0]), cols, atoi(argv[1])));
    return 0;
}
