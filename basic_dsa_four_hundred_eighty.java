import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Basic DSA Problems - One Fundamental Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty {

    // Problem 1: Intersection of Two Arrays
    // Given two integer arrays nums1 and nums2, return a list of distinct numbers that appear in
    // both arrays (order does not matter). This version returns a sorted int[] for easy printing.
    //
    // Example:
    // nums1 = [1,2,2,1], nums2 = [2,2] -> [2]
    // nums1 = [4,9,5], nums2 = [9,4,9,8,4] -> [4,9]

    /**
     * Put nums2 in a set, scan nums1 and collect values also in nums2 (dedup with another set)
     * Time Complexity: O(n + m)
     * Space Complexity: O(n + m)
     */
    public static int[] intersection(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            return null;
        }

        Set<Integer> inSecond = new HashSet<>();
        for (int x : nums2) {
            inSecond.add(x);
        }

        Set<Integer> both = new HashSet<>();
        for (int x : nums1) {
            if (inSecond.contains(x)) {
                both.add(x);
            }
        }

        int[] out = new int[both.size()];
        int i = 0;
        for (int x : both) {
            out[i++] = x;
        }
        Arrays.sort(out);
        return out;
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
        for (int j = 0; j < arr.length; j++) {
            if (j > 0) {
                sb.append(", ");
            }
            sb.append(arr[j]);
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
        System.out.println("nums1: " + arrayToString(a1));
        System.out.println("nums2: " + arrayToString(b1));
        System.out.println("Intersection: " + arrayToString(intersection(a1, b1)));

        int[] a2 = {4, 9, 5};
        int[] b2 = {9, 4, 9, 8, 4};
        System.out.println("\nnums1: " + arrayToString(a2));
        System.out.println("nums2: " + arrayToString(b2));
        System.out.println("Intersection: " + arrayToString(intersection(a2, b2)));

        int[] a3 = {1, 2, 3};
        int[] b3 = {4, 5, 6};
        System.out.println("\nnums1: " + arrayToString(a3));
        System.out.println("nums2: " + arrayToString(b3));
        System.out.println("Intersection: " + arrayToString(intersection(a3, b3)));

        int[] a4 = {};
        int[] b4 = {1};
        System.out.println("\nnums1: " + arrayToString(a4));
        System.out.println("nums2: " + arrayToString(b4));
        System.out.println("Intersection: " + arrayToString(intersection(a4, b4)));

        System.out.println("\nnums1: null, nums2: [1]");
        System.out.println("Intersection: " + arrayToString(intersection(null, new int[] {1})));
    }
}
