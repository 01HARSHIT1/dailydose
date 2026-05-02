/**
 * Basic DSA Problems - One Fundamental Array Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_four {

    // Problem 1: Move Zeroes
    // Given an integer array nums, move all 0's to the end of it while maintaining
    // the relative order of the non-zero elements.
    //
    // Do this in-place without making a copy of the array.
    //
    // Example:
    // nums = [0,1,0,3,12] -> [1,3,12,0,0]

    /**
     * Two-pointer in-place compaction
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] moveZeroes(int[] nums) {
        if (nums == null) {
            return null;
        }

        int insert = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[insert] = nums[i];
                insert++;
            }
        }

        while (insert < nums.length) {
            nums[insert] = 0;
            insert++;
        }

        return nums;
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
        System.out.println("Problem 1: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] a1 = {0, 1, 0, 3, 12};
        System.out.println("nums = [0, 1, 0, 3, 12] -> " + arrayToString(moveZeroes(a1)));

        int[] a2 = {0, 0, 1};
        System.out.println("nums = [0, 0, 1] -> " + arrayToString(moveZeroes(a2)));

        int[] a3 = {1, 2, 3};
        System.out.println("nums = [1, 2, 3] -> " + arrayToString(moveZeroes(a3)));

        int[] a4 = {};
        System.out.println("nums = [] -> " + arrayToString(moveZeroes(a4)));

        System.out.println("nums = null -> " + arrayToString(moveZeroes(null)));
    }
}
