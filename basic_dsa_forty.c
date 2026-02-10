/**
 * Basic DSA Problems - Binary Search (C)
 * Find index of target in sorted array, or -1 if not present
 */
#include <stdio.h>

/**
 * Classic binary search: narrow [lo, hi] by comparing mid with target.
 * Time O(log n), Space O(1)
 */
int binary_search(int *nums, int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main(void) {
    printf("============================================================\n");
    printf("Problem: Binary Search\n");
    printf("============================================================\n");

    int nums[] = {-1, 0, 3, 5, 9, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("target 9 -> %d\n", binary_search(nums, n, 9));
    printf("target 2 -> %d\n", binary_search(nums, n, 2));

    return 0;
}
