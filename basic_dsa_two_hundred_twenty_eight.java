/**
 * Basic DSA Problems - Sign of the Product of an Array
 * Return 1, -1, or 0 based on product sign (without computing product)
 */
public class basic_dsa_two_hundred_twenty_eight {

    // Problem: nums array. Return sign of product of all elements: 1 (positive), -1 (negative), 0 (zero).

    /**
     * Count negatives; if any zero return 0; else return -1 if neg count odd else 1.
     * Time O(n), Space O(1)
     */
    public static int arraySign(int[] nums) {
        int neg = 0;
        for (int x : nums) {
            if (x == 0) return 0;
            if (x < 0) neg++;
        }
        return neg % 2 == 0 ? 1 : -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sign of the Product of an Array");
        System.out.println("=".repeat(60));

        System.out.println("[-1,-2,-3,-4,3,2,1] -> " + arraySign(new int[]{-1, -2, -3, -4, 3, 2, 1}));
        System.out.println("[1,5,0,2,-3] -> " + arraySign(new int[]{1, 5, 0, 2, -3}));
        System.out.println("[-1,1,-1,1,-1] -> " + arraySign(new int[]{-1, 1, -1, 1, -1}));
    }
}
