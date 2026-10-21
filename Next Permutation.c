static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void reverse(int* nums, int l, int r) {
    while (l < r) {
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // 1. find first decreasing element from right
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
        // 2. find just-larger element from right
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) j--;

        // 3. swap
        swap(&nums[i], &nums[j]);
    }

    // 4. reverse the suffix
    reverse(nums, i + 1, numsSize - 1);
}