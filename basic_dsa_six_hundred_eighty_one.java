/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_one {

    // Problem 1: Single Element in a Sorted Array
    // Every element appears exactly twice except one element appears once.
    // nums is sorted in non-decreasing order; length is odd.

    /**
     * Pair neighbors using index parity: compare nums[mid] with nums[mid ^ 1].
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer singleNonDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        if (nums.length % 2 == 0) {
            return null;
        }

        int lo = 0;
        int hi = nums.length - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return nums[lo];
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Single Element in a Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 1, 2, 3, 3, 4, 4, 8, 8};
        System.out.println("[1,1,2,3,3,4,4,8,8] -> " + singleNonDuplicate(a));

        int[] b = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7};
        System.out.println("...,6,7,7 with lone 6 -> " + singleNonDuplicate(b));

        int[] c = {3};
        System.out.println("[3] -> " + singleNonDuplicate(c));

        int[] d = {1, 2, 2};
        System.out.println("[1,2,2] -> " + singleNonDuplicate(d));

        System.out.println("null -> " + singleNonDuplicate(null));
        System.out.println("even length [1,1] -> " + singleNonDuplicate(new int[] {1, 1}));
    }
}
