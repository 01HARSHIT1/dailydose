/**
 * Basic DSA Problems - Median of Two Sorted Arrays
 * Find median of two sorted arrays in O(log(min(n,m)))
 */
public class basic_dsa_one_hundred_eighty_six {

    // Problem: Two sorted arrays nums1, nums2. Return median of merged array. O(log(min(n,m))).

    /**
     * Binary search on smaller array: partition so left half has (n+m+1)/2 elements; median from partition.
     * Time O(log(min(n,m))), Space O(1)
     */
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.length, m = nums2.length;
        int half = (n + m + 1) / 2;
        int lo = 0, hi = n;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = half - i;
            int left1 = i == 0 ? Integer.MIN_VALUE : nums1[i - 1];
            int right1 = i == n ? Integer.MAX_VALUE : nums1[i];
            int left2 = j == 0 ? Integer.MIN_VALUE : nums2[j - 1];
            int right2 = j == m ? Integer.MAX_VALUE : nums2[j];
            if (left1 <= right2 && left2 <= right1) {
                if ((n + m) % 2 == 1) return Math.max(left1, left2);
                return (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;
            }
            if (left1 > right2) hi = i - 1;
            else lo = i + 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Median of Two Sorted Arrays");
        System.out.println("=".repeat(60));

        System.out.println("[1,3], [2] -> " + findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        System.out.println("[1,2], [3,4] -> " + findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
    }
}
