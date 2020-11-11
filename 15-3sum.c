#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *left, const void *right) {
    return *(const int *)left - *(const int *)right;
}

static int capacity = 8;
int **append_result(int **pp, int *size, int a, int b, int c) {
    int *p;
    if (*size >= capacity) {
        capacity *= 2;
        pp = (int **)realloc(pp, capacity * sizeof(int *));
    }
    p  = (int *)malloc(3 * sizeof(int));
    p[0] = a; p[1] = b; p[2] = c;
    pp[*size] = p;
    *size += 1;
    return pp;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, sum, count, *p;
    int **pp = NULL;
    count = 0;
    capacity = 8;
    pp = (int **)realloc(pp, capacity * sizeof(int *));
    qsort(nums, numsSize, sizeof(int), cmp_int);
    for (i = 0; i < numsSize; i++) {
        j   = i + 1;
        k   = numsSize - 1;
        sum = 0 - nums[i];
        if (nums[i] > 0 || nums[k] < 0) {
            break;
        }
        while (j < k) {
            if (nums[j] + nums[k] < sum) {
                j++;
            }else if (nums[j] + nums[k] > sum) {
                k--;
            }else {
                pp = append_result(pp, &count, nums[i], nums[j], nums[k]);
                while (j < k && nums[j] == nums[j+1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k-1]) {
                    k--;
                }
                j++;
                k--;
                while (i < j && nums[i] == nums[i+1]) {
                    i++;
                }
            }
        }
    }
    printf("total result:%d\n", count);
    for (i = 0; i < count; i++) {
        printf("[%d] [%d:%d:%d]\n", i, pp[i][0], pp[i][1], pp[i][2]);
    }
    *returnSize = count;
    p = (int *)malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        p[i] = 3;
    }
    *returnColumnSizes = p;
    return pp;
}

int main(int argc, char *argv[]) {
    int *column_size = NULL;
    int count = 0;
    int res_count = 0;
    int nums[4096];
    int **pp;
    FILE *fp;
    char line[64];

    if (argc < 2) {
        printf("usage:%s filename\n", argv[0]);
        return 0;
    }
    fp = fopen(argv[1], "r");
    if (NULL == fp) {
        perror("open file failed. ");
        return -1;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        nums[count++] = atoi(line);
    }
    fclose(fp);


    pp = threeSum(nums, count, &res_count, &column_size);
    return 0;
}
