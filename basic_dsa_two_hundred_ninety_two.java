/**
 * Basic DSA Problems - Two Sum II - Input Array Is Sorted
 * Find two indices with sum = target in sorted array
 */
public class basic_dsa_two_hundred_ninety_two {

    // Problem: Sorted array. Find indices (1-indexed) of two numbers that add to target.
    // Exactly one solution exists.

    /**
     * Two pointers: left at start, right at end. If sum < target, left++. Else right--.
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
        return new int[]{};
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum II - Input Array Is Sorted");
        System.out.println("=".repeat(60));

        System.out.println("[2,7,11,15], target=9 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9)));
        System.out.println("[2,3,4], target=6 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 3, 4}, 6)));
    }
}
