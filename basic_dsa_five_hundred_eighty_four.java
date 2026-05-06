/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_four {

    // Problem 1: Rotate Array
    // Given an integer array nums, rotate the array to the right by k steps.
    //
    // Example:
    // nums = [1,2,3,4,5,6,7], k = 3 -> [5,6,7,1,2,3,4]

    /**
     * Reverse three segments: whole array, first k, last n-k
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] rotate(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        int n = nums.length;
        k = k % n;
        if (k < 0) {
            k += n;
        }

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        return nums;
    }

    private static void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
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
        System.out.println("Problem 1: Rotate Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4, 5, 6, 7};
        System.out.println("rotate k=3 -> " + arrayToString(rotate(a, 3)));

        int[] b = {-1, -100, 3, 99};
        System.out.println("rotate k=2 -> " + arrayToString(rotate(b, 2)));

        int[] c = {1};
        System.out.println("rotate n=1 k=0 -> " + arrayToString(rotate(c, 0)));

        System.out.println("null -> " + arrayToString(rotate(null, 1)));
    }
}
