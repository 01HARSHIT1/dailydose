/**
 * Basic DSA Problems - Third Maximum Number
 * Return the third distinct maximum; if fewer than 3 distinct, return the maximum
 */
public class basic_dsa_one_hundred_forty_five {

    // Problem: Given integer array, return the third distinct maximum. If fewer than 3 distinct, return maximum.
    // Example: [3,2,1] -> 1, [1,2] -> 2, [2,2,3,1] -> 1

    /**
     * Keep track of top 3 using TreeSet or three variables
     * Time O(n), Space O(1)
     */
    public static int thirdMax(int[] nums) {
        Integer first = null, second = null, third = null;
        for (Integer n : nums) {
            if (n.equals(first) || n.equals(second) || n.equals(third)) continue;
            if (first == null || n > first) {
                third = second;
                second = first;
                first = n;
            } else if (second == null || n > second) {
                third = second;
                second = n;
            } else if (third == null || n > third) {
                third = n;
            }
        }
        return third != null ? third : first;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Third Maximum Number");
        System.out.println("=".repeat(60));

        System.out.println("[3,2,1] -> " + thirdMax(new int[] { 3, 2, 1 }));
        System.out.println("[1,2] -> " + thirdMax(new int[] { 1, 2 }));
        System.out.println("[2,2,3,1] -> " + thirdMax(new int[] { 2, 2, 3, 1 }));
        System.out.println("[1,1,2] -> " + thirdMax(new int[] { 1, 1, 2 }));
    }
}
