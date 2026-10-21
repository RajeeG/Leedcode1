int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            int pos = nums[i] - 1;
            int t = nums[pos];
            nums[pos] = nums[i];
            nums[i] = t;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) return i + 1;
    }

    return n + 1;
}