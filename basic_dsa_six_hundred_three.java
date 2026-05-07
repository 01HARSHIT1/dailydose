/**
 * Basic DSA Problems - One Fundamental Prefix / Suffix Product Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_three {

    // Problem 1: Product of Array Except Self
    // Return an array answer where answer[i] equals the product of all nums[j] with j != i.
    // Solve without division and in O(n) time.

    /**
     * Prefix products then suffix products in one extra pass
     * Time Complexity: O(n)
     * Space Complexity: O(1) excluding the output array
     */
    public static int[] productExceptSelf(int[] nums) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        int[] answer = new int[n];
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }

    private static String arrToString(int[] a) {
        if (a == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(a[i]);
        }
        return sb.append("]").toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Product of Array Except Self");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4};
        System.out.println("[1,2,3,4] -> " + arrToString(productExceptSelf(a)));

        int[] b = {-1, 1, 0, -3, 3};
        System.out.println("with zero -> " + arrToString(productExceptSelf(b)));

        int[] c = {2};
        System.out.println("[2] -> " + arrToString(productExceptSelf(c)));

        System.out.println("null -> " + arrToString(productExceptSelf(null)));
    }
}
