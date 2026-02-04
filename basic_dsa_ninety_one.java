/**
 * Basic DSA Problems - Two Sum II (Sorted Input)
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety_one {

    // Problem: Sorted array and target; find two indices (1-based) such that numbers add up to target.
    // Exactly one solution exists. Example: [2,7,11,15], target=9 -> [1,2]

    /**
     * Two pointers at start and end; move based on sum vs target.
     * Time O(n), Space O(1)
     */
    public static int[] twoSum(int[] numbers, int target) {
        if (numbers == null || numbers.length < 2) return null;
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return new int[] { i + 1, j + 1 };
            if (sum < target) i++;
            else j--;
        }
        return null;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum II (Sorted Input)");
        System.out.println("=".repeat(60));

        int[] a = { 2, 7, 11, 15 };
        int[] r = twoSum(a, 9);
        System.out.println("[2,7,11,15], target=9 -> [" + r[0] + "," + r[1] + "]");
    }
}
