/**
 * Basic DSA Problems - Move Zeroes
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety {

    // Problem: Move all 0's to the end while maintaining relative order of non-zero elements (in-place).
    // Example: [0,1,0,3,12] -> [1,3,12,0,0]

    /**
     * Two pointers: write index for next non-zero; scan and swap.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        if (nums == null) return;
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

        int[] a = { 0, 1, 0, 3, 12 };
        moveZeroes(a);
        System.out.print("[0,1,0,3,12] -> [");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) System.out.print(",");
            System.out.print(a[i]);
        }
        System.out.println("]");
    }
}
