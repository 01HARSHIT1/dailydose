/**
 * Basic DSA Problems - Squares of a Sorted Array
 * Return sorted array of squares of each element (array may have negatives)
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_five {

    // Problem: Given integer array nums sorted in non-decreasing order, return array of
    // squares of each number sorted in non-decreasing order.

    /**
     * Two pointers from both ends: compare absolute values, place larger square at end of result.
     * Time O(n), Space O(n) for result
     */
    public static int[] sortedSquares(int[] nums) {
        if (nums == null) return new int[0];
        int n = nums.length;
        int[] result = new int[n];
        int left = 0, right = n - 1, k = n - 1;
        while (left <= right) {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a >= b) {
                result[k--] = a;
                left++;
            } else {
                result[k--] = b;
                right--;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Squares of a Sorted Array");
        System.out.println("=".repeat(60));

        System.out.println("[-4,-1,0,3,10] -> " + Arrays.toString(sortedSquares(new int[] { -4, -1, 0, 3, 10 })));
        System.out.println("[-7,-3,2,3,11] -> " + Arrays.toString(sortedSquares(new int[] { -7, -3, 2, 3, 11 })));
    }
}
