/**
 * Basic DSA Problems - Maximum Subarray / Kadane's Algorithm (C)
 * Find contiguous subarray with the largest sum
 */
#include <stdio.h>

/**
 * Kadane: at each index, either extend current subarray or start fresh. Track max sum.
 * Time O(n), Space O(1)
 */
int max_subarray(int *nums, int n) {
    if (n <= 0) return 0;
    int cur = nums[0], max = nums[0];
    for (int i = 1; i < n; i++) {
        if (cur + nums[i] > nums[i])
            cur = cur + nums[i];
        else
            cur = nums[i];
        if (cur > max) max = cur;
    }
    return max;
}

int main(void) {
    printf("============================================================\n");
    printf("Problem: Maximum Subarray (Kadane)\n");
    printf("============================================================\n");

    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("Max subarray sum -> %d\n", max_subarray(nums, n));

    int nums2[] = {5, 4, -1, 7, 8};
    n = sizeof(nums2) / sizeof(nums2[0]);
    printf("Max subarray sum -> %d\n", max_subarray(nums2, n));

    return 0;
}
