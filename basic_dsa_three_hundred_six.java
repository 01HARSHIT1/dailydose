/**
 * Basic DSA Problems - Squares of a Sorted Array
 * Return sorted array of squares from sorted input
 */
public class basic_dsa_three_hundred_six {

    // Problem: Sorted array nums (possibly negative). Return sorted array of squares.

    /**
     * Two pointers: compare abs at both ends, fill result from right to left.
     * Time O(n), Space O(n) for output
     */
    public static int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] out = new int[n];
        int i = 0, j = n - 1, k = n - 1;
        while (i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a >= b) {
                out[k--] = a;
                i++;
            } else {
                out[k--] = b;
                j--;
            }
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Squares of a Sorted Array");
        System.out.println("=".repeat(60));

        System.out.println("[-4,-1,0,3,10] -> " + java.util.Arrays.toString(sortedSquares(new int[]{-4, -1, 0, 3, 10})));
        System.out.println("[-7,-3,2,3,11] -> " + java.util.Arrays.toString(sortedSquares(new int[]{-7, -3, 2, 3, 11})));
    }
}
