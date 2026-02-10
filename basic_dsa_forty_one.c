/**
 * Basic DSA Problems - Two Sum (C)
 * Find two indices such that nums[i] + nums[j] = target
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Brute force: check all pairs. Return indices (1-based in problem, 0-based here).
 * Time O(n^2), Space O(1)
 */
void two_sum(int *nums, int n, int target, int *out_i, int *out_j) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] + nums[j] == target) {
                *out_i = i;
                *out_j = j;
                return;
            }
    *out_i = *out_j = -1;
}

int main(void) {
    printf("============================================================\n");
    printf("Problem: Two Sum\n");
    printf("============================================================\n");

    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int i, j;
    two_sum(nums, n, target, &i, &j);

    printf("target %d -> indices %d, %d\n", target, i, j);

    int nums2[] = {3, 2, 4};
    n = sizeof(nums2) / sizeof(nums2[0]);
    target = 6;
    two_sum(nums2, n, target, &i, &j);
    printf("target %d -> indices %d, %d\n", target, i, j);

    return 0;
}
