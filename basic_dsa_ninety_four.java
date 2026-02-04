/**
 * Basic DSA Problems - Remove Duplicates from Sorted Array
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety_four {

    // Problem: Sorted array; remove duplicates in-place, return length of unique part.
    // Example: [1,1,2,2,3] -> length 3, nums = [1,2,3,_,_]

    /**
     * Two pointers: write index; copy only when different from previous.
     * Time O(n), Space O(1)
     */
    public static int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int w = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[w - 1]) {
                nums[w++] = nums[i];
            }
        }
        return w;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Duplicates from Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = { 1, 1, 2, 2, 3 };
        int len = removeDuplicates(a);
        System.out.print("[1,1,2,2,3] -> length " + len + ", [");
        for (int i = 0; i < len; i++) {
            if (i > 0) System.out.print(",");
            System.out.print(a[i]);
        }
        System.out.println("]");
    }
}
