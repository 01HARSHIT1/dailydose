/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighteen {

    // Problem 1: Search Insert Position
    // nums is sorted ascending with distinct values. Return index of target if present;
    // otherwise return the index where target would be inserted in order.

    /**
     * Standard lower-bound binary search: loop ends with lo == first index >= target
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer searchInsert(int[] nums, int target) {
        if (nums == null) {
            return null;
        }

        int lo = 0;
        int hi = nums.length - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Search Insert Position");
        System.out.println("=".repeat(60));

        int[] a = {1, 3, 5, 6};
        System.out.println("target 5 -> " + searchInsert(a, 5));
        System.out.println("target 2 -> " + searchInsert(a, 2));
        System.out.println("target 7 -> " + searchInsert(a, 7));

        int[] b = {1};
        System.out.println("[1] target 0 -> " + searchInsert(b, 0));

        System.out.println("null -> " + searchInsert(null, 1));
    }
}
