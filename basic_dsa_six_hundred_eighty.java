/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty {

    // Problem 1: Find Minimum in Rotated Sorted Array
    // nums was sorted ascending then rotated; all values are distinct.

    /**
     * Compare mid against right boundary to decide which half holds the pivot (minimum).
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer findMin(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int lo = 0;
        int hi = nums.length - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
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
        System.out.println("Problem 1: Find Minimum in Rotated Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = {3, 4, 5, 1, 2};
        System.out.println("[3,4,5,1,2] -> " + findMin(a));

        int[] b = {4, 5, 6, 7, 0, 1, 2};
        System.out.println("[4,5,6,7,0,1,2] -> " + findMin(b));

        int[] c = {11, 13, 15, 17};
        System.out.println("[11,13,15,17] (sorted) -> " + findMin(c));

        int[] d = {1};
        System.out.println("[1] -> " + findMin(d));

        System.out.println("null -> " + findMin(null));
        System.out.println("empty -> " + findMin(new int[0]));
    }
}
