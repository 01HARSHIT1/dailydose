/**
 * Basic DSA Problems - Find Minimum in Rotated Sorted Array
 * Min element in sorted array rotated at unknown pivot (no duplicates)
 */
public class basic_dsa_one_hundred_eighty_three {

    // Problem: Sorted array rotated at unknown pivot. Find minimum. No duplicates.

    /**
     * Binary search: if nums[mid] > nums[hi], min is in (mid, hi]; else min is in [lo, mid].
     * Time O(log n), Space O(1)
     */
    public static int findMin(int[] nums) {
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find Min in Rotated Sorted Array");
        System.out.println("=".repeat(60));

        System.out.println("[3,4,5,1,2] -> " + findMin(new int[]{3, 4, 5, 1, 2}));
        System.out.println("[4,5,6,7,0,1,2] -> " + findMin(new int[]{4, 5, 6, 7, 0, 1, 2}));
        System.out.println("[1] -> " + findMin(new int[]{1}));
    }
}
