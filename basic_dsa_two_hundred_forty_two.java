/**
 * Basic DSA Problems - Third Maximum Number
 * Return the third distinct maximum, or the maximum if less than 3 distinct values
 */
public class basic_dsa_two_hundred_forty_two {

    // Problem: Return third distinct maximum in nums. If fewer than 3 distinct, return max.
    // Use O(1) extra space.

    /**
     * Track top 3 distinct values. Use Long.MIN_VALUE for initial sentinel.
     * Time O(n), Space O(1)
     */
    public static int thirdMax(int[] nums) {
        long first = Long.MIN_VALUE, second = Long.MIN_VALUE, third = Long.MIN_VALUE;
        for (long x : nums) {
            if (x > first) {
                third = second;
                second = first;
                first = x;
            } else if (x < first && x > second) {
                third = second;
                second = x;
            } else if (x < second && x > third) {
                third = x;
            }
        }
        return (int) (third == Long.MIN_VALUE ? first : third);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Third Maximum Number");
        System.out.println("=".repeat(60));

        System.out.println("[3,2,1] -> " + thirdMax(new int[]{3, 2, 1}));
        System.out.println("[1,2] -> " + thirdMax(new int[]{1, 2}));
        System.out.println("[2,2,3,1] -> " + thirdMax(new int[]{2, 2, 3, 1}));
    }
}
