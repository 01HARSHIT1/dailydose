/**
 * Basic DSA Problems - One Fundamental Two Pointers Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_three {

    // Problem 1: Merge Sorted Array
    // You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    // and two integers m and n, representing the number of valid elements in nums1 and nums2.
    //
    // Merge nums2 into nums1 as one sorted array in-place.
    //
    // Example:
    // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    // Result: [1,2,2,3,5,6]

    /**
     * Fill from the end using two pointers
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static int[] mergeSortedArray(int[] nums1, int m, int[] nums2, int n) {
        if (nums1 == null || nums2 == null || m < 0 || n < 0 || m + n > nums1.length || n > nums2.length) {
            return null;
        }

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        return nums1;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Merge Sorted Array");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 3, 0, 0, 0};
        int[] b1 = {2, 5, 6};
        System.out.println("nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 -> "
                + arrayToString(mergeSortedArray(a1, 3, b1, 3)));

        int[] a2 = {1};
        int[] b2 = {};
        System.out.println("nums1 = [1], m = 1, nums2 = [], n = 0 -> "
                + arrayToString(mergeSortedArray(a2, 1, b2, 0)));

        int[] a3 = {0};
        int[] b3 = {1};
        System.out.println("nums1 = [0], m = 0, nums2 = [1], n = 1 -> "
                + arrayToString(mergeSortedArray(a3, 0, b3, 1)));

        System.out.println("invalid input -> " + arrayToString(mergeSortedArray(null, 0, b3, 1)));
    }
}
