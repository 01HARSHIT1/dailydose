/**
 * Basic DSA Problems - One Fundamental Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_five {

    // Problem 1: Intersection of Two Arrays
    // Given two integer arrays nums1 and nums2, return an array of their intersection.
    // Each element in the result must be unique and you may return the result in any order.
    //
    // Example:
    // nums1 = [1,2,2,1], nums2 = [2,2] -> [2]

    /**
     * Use hash sets to keep unique values and test membership
     * Time Complexity: O(n + m)
     * Space Complexity: O(n + m)
     */
    public static int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            return null;
        }

        java.util.HashSet<Integer> set1 = new java.util.HashSet<>();
        for (int n : nums1) {
            set1.add(n);
        }

        java.util.HashSet<Integer> resultSet = new java.util.HashSet<>();
        for (int n : nums2) {
            if (set1.contains(n)) {
                resultSet.add(n);
            }
        }

        int[] result = new int[resultSet.size()];
        int index = 0;
        for (int n : resultSet) {
            result[index++] = n;
        }
        return result;
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
        System.out.println("Problem 1: Intersection of Two Arrays");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 2, 1};
        int[] b1 = {2, 2};
        System.out.println("nums1 = " + arrayToString(a1) + ", nums2 = " + arrayToString(b1)
                + " -> " + arrayToString(intersection(a1, b1)));

        int[] a2 = {4, 9, 5};
        int[] b2 = {9, 4, 9, 8, 4};
        System.out.println("nums1 = " + arrayToString(a2) + ", nums2 = " + arrayToString(b2)
                + " -> " + arrayToString(intersection(a2, b2)));

        int[] a3 = {};
        int[] b3 = {1, 2};
        System.out.println("nums1 = " + arrayToString(a3) + ", nums2 = " + arrayToString(b3)
                + " -> " + arrayToString(intersection(a3, b3)));

        System.out.println("nums1 = null, nums2 = [1] -> " + arrayToString(intersection(null, new int[]{1})));
    }
}
