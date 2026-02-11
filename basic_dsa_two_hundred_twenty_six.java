/**
 * Basic DSA Problems - Move Zeroes
 * Move all 0's to the end while maintaining relative order of non-zero elements
 */
public class basic_dsa_two_hundred_twenty_six {

    // Problem: In-place. Move all 0s to the end. Relative order of non-zero must stay.

    /**
     * Two pointers: write index for next non-zero. Scan; when non-zero, swap with write and advance write.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        int w = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i != w) {
                    int t = nums[w];
                    nums[w] = nums[i];
                    nums[i] = t;
                }
                w++;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] nums = {0, 1, 0, 3, 12};
        moveZeroes(nums);
        System.out.println("Result -> " + java.util.Arrays.toString(nums));
    }
}
