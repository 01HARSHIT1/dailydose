/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixty_eight {

    // Problem: Remove Duplicates from Sorted Array (in-place)
    // Return the number of unique elements; first k slots should hold unique elements in order.
    // Example: [1,1,2,2,3] -> k=3, array becomes [1,2,3,...]

    /**
     * Remove duplicates in-place, return count of unique elements
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int k = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Duplicates from Sorted Array");
        System.out.println("=".repeat(60));

        int[] a1 = { 1, 1, 2, 2, 3 };
        int k1 = removeDuplicates(a1);
        System.out.println("Input: [1,1,2,2,3] -> k = " + k1 + ", unique: " + Arrays.toString(Arrays.copyOf(a1, k1)));

        int[] a2 = { 1, 2, 3 };
        int k2 = removeDuplicates(a2);
        System.out.println("Input: [1,2,3] -> k = " + k2 + ", unique: " + Arrays.toString(Arrays.copyOf(a2, k2)));

        int[] a3 = { 1, 1, 1 };
        int k3 = removeDuplicates(a3);
        System.out.println("Input: [1,1,1] -> k = " + k3 + ", unique: " + Arrays.toString(Arrays.copyOf(a3, k3)));
    }
}
