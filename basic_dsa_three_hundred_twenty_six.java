/**
 * Basic DSA Problems - Rotate Array
 * Rotate array to the right by k steps
 */
public class basic_dsa_three_hundred_twenty_six {

    // Problem: Array nums and k. Rotate array to the right by k steps in-place.

    /**
     * Reverse entire array, then reverse first k, then reverse rest.
     * Time O(n), Space O(1)
     */
    public static void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    static void reverse(int[] a, int lo, int hi) {
        while (lo < hi) {
            int t = a[lo];
            a[lo] = a[hi];
            a[hi] = t;
            lo++;
            hi--;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Rotate Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4, 5, 6, 7};
        rotate(a, 3);
        System.out.println("[1,2,3,4,5,6,7], k=3 -> " + java.util.Arrays.toString(a));

        int[] b = {-1, -100, 3, 99};
        rotate(b, 2);
        System.out.println("[-1,-100,3,99], k=2 -> " + java.util.Arrays.toString(b));
    }
}
