/**
 * Basic DSA Problems - One Fundamental Bit Manipulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_sixteen {

    // Problem 1: Single Number
    // Every element appears twice except one; find that unique element.

    /**
     * XOR: pairs cancel (a ^ a == 0), identity 0
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer singleNumber(int[] nums) {
        if (nums == null) {
            return null;
        }

        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Single Number");
        System.out.println("=".repeat(60));

        int[] a = {2, 2, 1};
        System.out.println("[2,2,1] -> " + singleNumber(a));

        int[] b = {4, 1, 2, 1, 2};
        System.out.println("[4,1,2,1,2] -> " + singleNumber(b));

        int[] c = {7};
        System.out.println("[7] -> " + singleNumber(c));

        System.out.println("empty -> " + singleNumber(new int[0]));
        System.out.println("null -> " + singleNumber(null));
    }
}
