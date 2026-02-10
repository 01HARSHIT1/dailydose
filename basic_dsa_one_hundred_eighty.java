/**
 * Basic DSA Problems - Binary Search
 * Find index of target in sorted array, or -1 if not present
 */
public class basic_dsa_one_hundred_eighty {

    // Problem: Sorted array and target. Return index of target, or -1.

    /**
     * Classic binary search: narrow [lo, hi] by comparing mid with target.
     * Time O(log n), Space O(1)
     */
    public static int binarySearch(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Binary Search");
        System.out.println("=".repeat(60));

        int[] nums = {-1, 0, 3, 5, 9, 12};
        System.out.println("target 9 -> " + binarySearch(nums, 9));
        System.out.println("target 2 -> " + binarySearch(nums, 2));
    }
}
