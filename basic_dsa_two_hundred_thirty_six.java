/**
 * Basic DSA Problems - Move Zeroes
 * Move all zeros to the end while maintaining relative order of non-zero elements
 */
public class basic_dsa_two_hundred_thirty_six {

    // Problem: Modify nums in-place. Move all 0's to the end. Keep non-zero order.
    // Example: [0,1,0,3,12] -> [1,3,12,0,0]

    /**
     * Two pointers: write index for next non-zero. Scan and swap non-zeros forward.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        int w = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i != w) {
                    nums[w] = nums[i];
                    nums[i] = 0;
                }
                w++;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] a = {0, 1, 0, 3, 12};
        moveZeroes(a);
        System.out.println("[0,1,0,3,12] -> " + java.util.Arrays.toString(a));

        int[] b = {0};
        moveZeroes(b);
        System.out.println("[0] -> " + java.util.Arrays.toString(b));
    }
}
