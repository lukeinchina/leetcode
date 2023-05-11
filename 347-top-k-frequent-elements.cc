#include <stdio.h>

#include <vector>
#include <queue>

struct ElemFreq {
    int key;
    int val;
};

class mycomparison
{
    public:
        bool operator() (const ElemFreq &lhs, const ElemFreq &rhs) const
        {
            return (lhs.val > rhs.val);
        }
};

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> topk;
    sort(nums.begin(), nums.end());

    priority_queue<ElemFreq, vector<ElemFreq>, mycomparison> pq;

    int i, size = nums.size();
    int freq = 1;
    ElemFreq e;
    for (i = 0; i < size; i++) {
        if (i+1 < size && nums[i] == nums[i+1]) {
            freq += 1;
            continue;
        }
        e.key = nums[i];
        e.val = freq;

        if (pq.size() < k) {
            pq.push(e);
        } else if (pq.top().val < e.val) {
            pq.pop();
            pq.push(e);
        }

        freq = 1;
    }
    while (!pq.empty()) {
        topk.push_back(pq.top().key);
        pq.pop();
    }
    return topk;
}

/*--------------------------------------------------------*/
struct HeapHead {
    int             size;
    int             capacity;
    struct ElemFreq *elems;
};

struct HeapHead create_heap(int max) {
    struct HeapHead h = {0, max+1, NULL};
    h.elems = (int *)malloc(sizeof(struct ElemFreq) * (max+1));
    h.elems[0] = {0, INT_MIN}; /* sentinel */
    return h;
}

void destory_heap(struct HeapHead h) {
    free(h.elems);
}

void insert_tail(struct HeapHead h, struct ElemFreq e) {
    int i = ++h.size;
    for (; e.freq < h.elems[i/2].freq; i /= 2) {
        h.elems[i] = h.elems[i/2];
    }
    h.elems[i] = e;
}

/* min heap */
int insert_heap(struct HeapHead h, struct ElemFreq e) {
    int i = 0;
    if (h.size < h.capacity) {
        return;
    } else if (e.val <= h.elems[0].val) {
        return -1;
    } else {
        /* 删除最小元 */
    }
}


/*--------------------------------------------------------*/
int int_cmp(const void *l, const void *r) {
    return *(const int *)l - *(const int*)r;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int i, n = 1;
    int *p = NULL;
    qsort(nums, numsSize, sizeof(nums[0]), int_cmp);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            n++;
        }
    }
    *returnSize = n;

    p = (int *)malloc(sizeof(nums[0]) * n);
    n = 0;
    for (i = 0; i < numsSize; i++) {
        p[n] = nums[i];
        if (i+1 < numsSize && nums[i] != nums[i+1]) {
            n++;
        }
    }
    return p;
}

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(void) {
    /* [4,1,-1,2,-1,2,3] */
    int nums[] = {4,1,-1,2,-1,2,3};
    int i, k = 2;
    vector<int> vec;
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        vec.push_back(nums[i]);
    }
    vector<int> rst = topKFrequent(vec, k);
    for (i = 0; i < rst.size(); i++) {
        printf("%d\t", rst[i]);
    }
    printf("\n");

    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    int size = 0;
    int *p = topKFrequent(nums, sizeof(nums) / sizeof(nums[0]), k, &size);
    print_array(p, size);
    free(p);
    return 0;
}
