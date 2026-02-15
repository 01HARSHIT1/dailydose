/**
 * Basic DSA Problems - Two Sum II (Sorted Array)
 * Find two indices that sum to target
 */
public class basic_dsa_three_hundred_fifteen {

    // Problem: Sorted array and target. Return 1-indexed [i, j] where nums[i]+nums[j]=target.

    /**
     * Two pointers: if sum < target, move left++; if sum > target, move right--.
     * Time O(n), Space O(1)
     */
    public static int[] twoSum(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int s = numbers[i] + numbers[j];
            if (s == target) return new int[]{i + 1, j + 1};
            if (s < target) i++;
            else j--;
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum II (Input Array Is Sorted)");
        System.out.println("=".repeat(60));

        System.out.println("[2,7,11,15], 9 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9)));
        System.out.println("[2,3,4], 6 -> " + java.util.Arrays.toString(twoSum(new int[]{2, 3, 4}, 6)));
        System.out.println("[-1,0], -1 -> " + java.util.Arrays.toString(twoSum(new int[]{-1, 0}, -1)));
    }
}
