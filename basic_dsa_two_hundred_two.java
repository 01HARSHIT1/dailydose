/**
 * Basic DSA Problems - Product of Array Except Self
 * Return array where output[i] = product of all elements except nums[i] (no division, O(n))
 */
public class basic_dsa_two_hundred_two {

    // Problem: Return array such that out[i] = product of all nums except nums[i]. O(n), no division.

    /**
     * Two passes: first store prefix products in output, then multiply by suffix from the right.
     * Time O(n), Space O(1) excluding output
     */
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] out = new int[n];
        out[0] = 1;
        for (int i = 1; i < n; i++)
            out[i] = out[i - 1] * nums[i - 1];
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            out[i] *= suffix;
            suffix *= nums[i];
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Product of Array Except Self");
        System.out.println("=".repeat(60));

        int[] nums = {1, 2, 3, 4};
        System.out.println("Result -> " + java.util.Arrays.toString(productExceptSelf(nums)));
    }
}
