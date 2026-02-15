/**
 * Basic DSA Problems - Move Zeroes
 * Move all zeros to the end in-place
 */
public class basic_dsa_three_hundred_fourteen {

    // Problem: Array nums. Move all 0s to the end while keeping relative order of non-zeros.

    /**
     * Two pointers: swap non-zero with next position; all zeros bubble right.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        int w = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int t = nums[w];
                nums[w] = nums[i];
                nums[i] = t;
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
