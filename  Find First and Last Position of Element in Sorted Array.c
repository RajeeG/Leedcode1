
static int lowerBound(int* nums, int n, int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    res[0] = -1;
    res[1] = -1;

    int first = lowerBound(nums, numsSize, target);

    
    if (first == numsSize || nums[first] != target) return res;


    int last = lowerBound(nums, numsSize, target + 1) - 1;

    res[0] = first;
    res[1] = last;
    return res;
}