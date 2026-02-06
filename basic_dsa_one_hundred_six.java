/**
 * Basic DSA Problems - Rotate Array
 * Rotate array to the right by k steps (in-place)
 */
public class basic_dsa_one_hundred_six {

    // Problem: Given integer array nums and non-negative k, rotate the array to the right by k steps.
    // Do it in-place with O(1) extra space.

    /** Reverse a range [left, right] in-place */
    private static void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int t = nums[left];
            nums[left] = nums[right];
            nums[right] = t;
            left++;
            right--;
        }
    }

    /**
     * Reverse whole array, then reverse first k, then reverse rest. Equivalent to right-rotate by k.
     * Time O(n), Space O(1)
     */
    public static void rotate(int[] nums, int k) {
        if (nums == null || nums.length == 0) return;
        int n = nums.length;
        k = k % n;
        if (k == 0) return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Rotate Array");
        System.out.println("=".repeat(60));

        int[] a = { 1, 2, 3, 4, 5, 6, 7 };
        rotate(a, 3);
        System.out.println("[1,2,3,4,5,6,7], k=3 -> " + java.util.Arrays.toString(a));

        int[] b = { -1, -100, 3, 99 };
        rotate(b, 2);
        System.out.println("[-1,-100,3,99], k=2 -> " + java.util.Arrays.toString(b));
    }
}
