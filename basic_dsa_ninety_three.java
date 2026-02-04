/**
 * Basic DSA Problems - Remove Element
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety_three {

    // Problem: Remove all occurrences of val in-place; return new length. Order can change.
    // Example: nums = [3,2,2,3], val = 3 -> length 2, nums = [2,2,_,_]

    /**
     * Two pointers: write index; copy only elements != val.
     * Time O(n), Space O(1)
     */
    public static int removeElement(int[] nums, int val) {
        if (nums == null) return 0;
        int w = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[w++] = nums[i];
            }
        }
        return w;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Element");
        System.out.println("=".repeat(60));

        int[] a = { 3, 2, 2, 3 };
        int len = removeElement(a, 3);
        System.out.print("[3,2,2,3], val=3 -> length " + len + ", [");
        for (int i = 0; i < len; i++) {
            if (i > 0) System.out.print(",");
            System.out.print(a[i]);
        }
        System.out.println("]");
    }
}
