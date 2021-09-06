#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define HEAP_SIZE 128
#define LeftChild(i) (2 *(i) + 1)

int cmp_int(const void *left, const void *right) {
    return *(const int *)left - *(const int *)right;
}

double difftimeval(const struct timeval *start, const struct timeval *end)
{
        double d;
        time_t s;
        suseconds_t u;

        s = start->tv_sec - end->tv_sec;
        u = start->tv_usec - end->tv_usec;
        //if (u < 0)
        //        --s;

        d = s;
        d *= 1000000.0;//1 秒 = 10^6 微秒
        d += u;

        return d;
}

/* min heap; 求最大值用 */
void PercDown(int *nums, int i, int n) {
    int child;
    int tmp;
    for (tmp = nums[i]; LeftChild(i) < n; i = child) {
        child = LeftChild(i);
        if (child+1 < n && nums[child+1] < nums[child]) {
            child++;
        }

        if (tmp > nums[child]) {
            nums[i] = nums[child];
        }else {
            break;
        }
    }
    nums[i] = tmp;
}

int
main(int argc, char *argv[]) {
    int i = 0;
    char line[HEAP_SIZE];
    int nums[20000];
    int heap[HEAP_SIZE];
    struct timeval begin, end;
    FILE *fp;
    if (argc < 2) {
        printf("usage:%s filename\n", argv[0]);
        return -1;
    }
    fp = fopen(argv[1], "r");
    if (NULL == fp) {
        perror("fopen failed:");
        return -1;
    }
    i = 0;
    while (NULL != fgets(line, sizeof(line), fp)) {
        nums[i++] = atoi(line);
    }
    fclose(fp);
    gettimeofday(&begin, NULL);
    memcpy(heap, nums, sizeof(heap));
    for (i = HEAP_SIZE / 2; i >= 0; i--) {
        PercDown(heap, i, HEAP_SIZE);
    }
    for (i = HEAP_SIZE; i < 20000; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            PercDown(heap, 0, HEAP_SIZE);
        }
    }
    gettimeofday(&end, NULL);
    printf("%f\n", difftimeval(&end, &begin));
    return 0;
    for (i = 0; i < HEAP_SIZE; i++) {
        printf("%d\n", heap[i]);
    }
    return 0;
}
