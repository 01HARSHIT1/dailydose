/**
 * Basic DSA Problems - Two Sum II (Input Array Is Sorted)
 * Find two numbers that add up to target using sorted array
 */
public class basic_dsa_three_hundred_two {

    // Problem: Sorted array numbers, find indices (1-based) of two numbers that add to target.
    // Exactly one solution exists.

    /**
     * Two pointers: left at start, right at end. Move based on sum vs target.
     * Time O(n), Space O(1)
     */
    public static int[] twoSum(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return new int[]{i + 1, j + 1};
            if (sum < target) i++;
            else j--;
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum II (Input Array Is Sorted)");
        System.out.println("=".repeat(60));

        System.out.println("[2,7,11,15] target=9 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9)));
        System.out.println("[2,3,4] target=6 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 3, 4}, 6)));
        System.out.println("[-1,0] target=-1 -> " + java.util.Arrays.toString(twoSum(new int[]{-1, 0}, -1)));
    }
}
