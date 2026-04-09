import java.util.Iterator;
import java.util.TreeSet;

/**
 * Basic DSA Problems - One Fundamental Set/Ordering Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_one {

    // Problem 1: Third Maximum Number
    // Given an integer array nums, return the third distinct maximum number in this array.
    // If the third maximum does not exist, return the maximum number.
    //
    // Example:
    // nums = [3,2,1] -> 1
    // nums = [1,2] -> 2
    // nums = [2,2,3,1] -> 1

    /**
     * Collect distinct values in a TreeSet; walk from largest to smallest
     * Time Complexity: O(n log k) with k = distinct values (at most n)
     * Space Complexity: O(k)
     */
    public static Integer thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        TreeSet<Integer> distinct = new TreeSet<>();
        for (int x : nums) {
            distinct.add(x);
        }

        if (distinct.size() < 3) {
            return distinct.last();
        }

        Iterator<Integer> it = distinct.descendingIterator();
        it.next();
        it.next();
        return it.next();
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
        System.out.println("Problem 1: Third Maximum Number");
        System.out.println("=".repeat(60));

        int[] a1 = {3, 2, 1};
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("Result: " + thirdMax(a1));

        int[] a2 = {1, 2};
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("Result: " + thirdMax(a2));

        int[] a3 = {2, 2, 3, 1};
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("Result: " + thirdMax(a3));

        int[] a4 = {5, 5, 5};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("Result: " + thirdMax(a4));

        int[] a5 = {};
        System.out.println("\nnums: " + arrayToString(a5));
        System.out.println("Result: " + thirdMax(a5));

        System.out.println("\nnums: null");
        System.out.println("Result: " + thirdMax(null));
    }
}
