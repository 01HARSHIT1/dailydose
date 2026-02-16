/**
 * Basic DSA Problems - Merge Sorted Array
 * Merge two sorted arrays into the first in-place
 */
public class basic_dsa_three_hundred_twenty_seven {

    // Problem: nums1 (length m+n, first m valid), nums2 (length n). Merge into nums1 in-place.

    /**
     * Three pointers from end: fill nums1 from right, pick larger of nums1[i] vs nums2[j].
     * Time O(m+n), Space O(1)
     */
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Merge Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 0, 0, 0};
        merge(a, 3, new int[]{2, 5, 6}, 3);
        System.out.println("[1,2,3,0,0,0] + [2,5,6] -> " + java.util.Arrays.toString(a));

        int[] b = {1};
        merge(b, 1, new int[]{}, 0);
        System.out.println("[1] + [] -> " + java.util.Arrays.toString(b));
    }
}
