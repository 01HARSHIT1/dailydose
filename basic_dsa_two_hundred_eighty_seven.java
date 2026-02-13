/**
 * Basic DSA Problems - Product of Array Except Self
 * Return array where output[i] = product of all elements except nums[i]
 */
public class basic_dsa_two_hundred_eighty_seven {

    // Problem: output[i] = product of all nums except nums[i]. O(n) time, O(1) extra space.
    // Cannot use division.

    /**
     * Two passes: left products then right. Or prefix * suffix in one output array.
     * Time O(n), Space O(1) excluding output
     */
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] out = new int[n];
        out[0] = 1;
        for (int i = 1; i < n; i++) out[i] = out[i - 1] * nums[i - 1];
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            out[i] *= right;
            right *= nums[i];
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Product of Array Except Self");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,4] -> " + java.util.Arrays.toString(productExceptSelf(new int[]{1, 2, 3, 4})));
        System.out.println("[-1,1,0,-3,3] -> " + java.util.Arrays.toString(productExceptSelf(new int[]{-1, 1, 0, -3, 3})));
    }
}
