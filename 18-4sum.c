#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *left, const void *right) {
    return *(const int *)left - *(const int *)right;
}

static int capacity = 8;
int **append_result(int **pp, int *size, int a, int b, int c, int d) {
    int *p;
    if (*size >= capacity) {
        capacity *= 2;
        pp = (int **)realloc(pp, capacity * sizeof(int *));
    }
    p  = (int *)malloc(4 * sizeof(int));
    p[0] = a; p[1] = b; p[2] = c; p[3] = d;
    pp[*size] = p;
    *size += 1;
    return pp;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int i, j, l, r, sum, count, *p;
    int **pp = NULL;
    count = 0;
    capacity = 8;
    pp = (int **)realloc(pp, capacity * sizeof(int *));
    qsort(nums, numsSize, sizeof(int), cmp_int);
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > sum) {
            break;
        }
        for (j = i+1; j < numsSize; j++) {
            l = j + 1;
            r = numsSize - 1;
            sum = target - nums[i] - nums[j];
            while (l < r) {
                if (nums[l] + nums[r] < sum) {
                    l++;
                    continue;
                }else if (nums[l] + nums[r] > sum) {
                    r--;
                    continue;
                }

                /* find */
                pp = append_result(pp, &count, nums[i], nums[j], nums[l], nums[r]);
                while (l < r && nums[l] == nums[l+1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r-1]) {
                    r--;
                }
                l++;r--;

                while (j < l && nums[j] == nums[j+1]) {
                    j++;
                }
                while (i < j && nums[i] == nums[i+1]) {
                    i++;
                }
            }
        }
    }
    printf("total result:%d\n", count);
    for (i = 0; i < count; i++) {
        printf("[%d] [%d:%d:%d:%d]\n", i, pp[i][0], pp[i][1], pp[i][2], pp[i][3]);
    }
    *returnSize = count;
    p = (int *)malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        p[i] = 4;
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


    pp = fourSum(nums, count, 0, &res_count, &column_size);
    return 0;
}
