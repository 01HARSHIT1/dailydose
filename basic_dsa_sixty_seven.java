/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixty_seven {

    // Problem: Merge Two Sorted Arrays
    // Given two sorted arrays, merge them into one sorted array.
    // Example: [1,3,5] & [2,4,6] -> [1,2,3,4,5,6]

    /**
     * Merge two sorted arrays into one sorted array
     * Time Complexity: O(m + n)
     * Space Complexity: O(m + n)
     */
    public static int[] mergeSortedArrays(int[] a, int[] b) {
        if (a == null) a = new int[0];
        if (b == null) b = new int[0];
        int m = a.length, n = b.length;
        int[] result = new int[m + n];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (a[i] <= b[j]) {
                result[k++] = a[i++];
            } else {
                result[k++] = b[j++];
            }
        }
        while (i < m) result[k++] = a[i++];
        while (j < n) result[k++] = b[j++];
        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Merge Two Sorted Arrays");
        System.out.println("=".repeat(60));

        int[] a1 = { 1, 3, 5 }, b1 = { 2, 4, 6 };
        System.out.println("Merge " + Arrays.toString(a1) + " & " + Arrays.toString(b1));
        System.out.println(" -> " + Arrays.toString(mergeSortedArrays(a1, b1)));

        int[] a2 = { 1, 2 }, b2 = { 3, 4, 5 };
        System.out.println("Merge " + Arrays.toString(a2) + " & " + Arrays.toString(b2));
        System.out.println(" -> " + Arrays.toString(mergeSortedArrays(a2, b2)));

        int[] a3 = { }, b3 = { 1 };
        System.out.println("Merge " + Arrays.toString(a3) + " & " + Arrays.toString(b3));
        System.out.println(" -> " + Arrays.toString(mergeSortedArrays(a3, b3)));
    }
}
