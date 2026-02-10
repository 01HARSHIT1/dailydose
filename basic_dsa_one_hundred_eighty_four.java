/**
 * Basic DSA Problems - Search in Rotated Sorted Array
 * Find target index in sorted array rotated at unknown pivot (no duplicates)
 */
public class basic_dsa_one_hundred_eighty_four {

    // Problem: Sorted array rotated at unknown pivot. Return index of target, or -1.

    /**
     * Binary search: one of [lo,mid] or [mid,hi] is sorted. Check which and narrow.
     * Time O(log n), Space O(1)
     */
    public static int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid]) {
                if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Search in Rotated Sorted Array");
        System.out.println("=".repeat(60));

        System.out.println("[4,5,6,7,0,1,2], target 0 -> " + search(new int[]{4, 5, 6, 7, 0, 1, 2}, 0));
        System.out.println("[4,5,6,7,0,1,2], target 3 -> " + search(new int[]{4, 5, 6, 7, 0, 1, 2}, 3));
    }
}
