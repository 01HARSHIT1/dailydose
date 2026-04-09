/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_two {

    // Problem 1: Search Insert Position
    // Given a sorted array of distinct integers nums and a target value, return the index if target
    // is found. If not, return the index where it would be inserted in order (still sorted).
    //
    // Example:
    // nums = [1,3,5,6], target = 5 -> 2
    // nums = [1,3,5,6], target = 2 -> 1
    // nums = [1,3,5,6], target = 7 -> 4

    /**
     * Binary search; when not found, left is the insertion index
     * Time Complexity: O(log n)
     * Space Complexity: O(1)
     */
    public static Integer searchInsert(int[] nums, int target) {
        if (nums == null) {
            return null;
        }

        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Search Insert Position");
        System.out.println("=".repeat(60));

        int[] nums = {1, 3, 5, 6};

        System.out.println("nums: " + arrayToString(nums));
        System.out.println("target = 5 -> index: " + searchInsert(nums, 5));
        System.out.println("target = 2 -> index: " + searchInsert(nums, 2));
        System.out.println("target = 7 -> index: " + searchInsert(nums, 7));
        System.out.println("target = 0 -> index: " + searchInsert(nums, 0));

        int[] empty = {};
        System.out.println("\nnums: " + arrayToString(empty));
        System.out.println("target = 1 -> index: " + searchInsert(empty, 1));

        System.out.println("\nnums: null");
        System.out.println("target = 1 -> index: " + searchInsert(null, 1));
    }
}
