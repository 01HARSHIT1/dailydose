/**
 * Basic DSA Problems - Two Sum II (Input Array Is Sorted)
 * Find two indices in sorted array that add up to target (1-indexed)
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_eight {

    // Problem: Given 1-indexed sorted array and target, return indices [i, j] (i < j)
    // such that numbers[i] + numbers[j] == target. Exactly one solution exists.

    /**
     * Two pointers: left at start, right at end; if sum < target move left, else if sum > target move right.
     * Time O(n), Space O(1)
     */
    public static int[] twoSum(int[] numbers, int target) {
        if (numbers == null || numbers.length < 2) return new int[] { -1, -1 };
        int left = 0, right = numbers.length - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return new int[] { left + 1, right + 1 };
            if (sum < target) left++;
            else right--;
        }
        return new int[] { -1, -1 };
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum II (Input Array Is Sorted)");
        System.out.println("=".repeat(60));

        System.out.println("[2,7,11,15], target=9 -> " + Arrays.toString(twoSum(new int[] { 2, 7, 11, 15 }, 9)));
        System.out.println("[2,3,4], target=6 -> " + Arrays.toString(twoSum(new int[] { 2, 3, 4 }, 6)));
        System.out.println("[-1,0], target=-1 -> " + Arrays.toString(twoSum(new int[] { -1, 0 }, -1)));
    }
}
