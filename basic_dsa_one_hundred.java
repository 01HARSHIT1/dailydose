/**
 * Basic DSA Problems - Merge Two Sorted Arrays
 * Merge two sorted arrays into one sorted array
 */
import java.util.*;

public class basic_dsa_one_hundred {

    // Problem: Given two sorted integer arrays nums1 and nums2, merge them into a single sorted array.
    // Assume nums1 and nums2 are non-null and may have different lengths.

    /**
     * Two pointers: compare front of each array, take smaller, advance pointer.
     * Time O(m+n), Space O(m+n) for result
     */
    public static int[] mergeSortedArrays(int[] nums1, int[] nums2) {
        if (nums1 == null) return nums2 == null ? new int[0] : nums2.clone();
        if (nums2 == null) return nums1.clone();

        int m = nums1.length, n = nums2.length;
        int[] result = new int[m + n];
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                result[k++] = nums1[i++];
            } else {
                result[k++] = nums2[j++];
            }
        }
        while (i < m) result[k++] = nums1[i++];
        while (j < n) result[k++] = nums2[j++];

        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Merge Two Sorted Arrays");
        System.out.println("=".repeat(60));

        int[] a = { 1, 3, 5 };
        int[] b = { 2, 4, 6 };
        System.out.println("[1,3,5] + [2,4,6] -> " + Arrays.toString(mergeSortedArrays(a, b)));

        int[] c = { 1, 2, 3 };
        int[] d = { 4, 5, 6 };
        System.out.println("[1,2,3] + [4,5,6] -> " + Arrays.toString(mergeSortedArrays(c, d)));

        int[] e = { 2, 4 };
        int[] f = { 1, 3, 5 };
        System.out.println("[2,4] + [1,3,5] -> " + Arrays.toString(mergeSortedArrays(e, f)));
    }
}
