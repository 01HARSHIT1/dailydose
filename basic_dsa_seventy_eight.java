/**
 * Basic DSA Problems - Intersection of Two Arrays II
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_eight {

    // Problem: Return intersection of two arrays (each element as many times as it appears in both).
    // Example: nums1 = [1,2,2,1], nums2 = [2,2] -> [2,2]

    /**
     * Count frequency in first array, decrement when found in second; collect result.
     * Time O(m+n), Space O(min(m,n))
     */
    public static int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) return new int[0];
        if (nums1.length > nums2.length) return intersect(nums2, nums1);

        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums1) freq.put(x, freq.getOrDefault(x, 0) + 1);

        List<Integer> list = new ArrayList<>();
        for (int x : nums2) {
            int count = freq.getOrDefault(x, 0);
            if (count > 0) {
                list.add(x);
                freq.put(x, count - 1);
            }
        }

        int[] out = new int[list.size()];
        for (int i = 0; i < list.size(); i++) out[i] = list.get(i);
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Intersection of Two Arrays II");
        System.out.println("=".repeat(60));

        int[] a1 = { 1, 2, 2, 1 }, b1 = { 2, 2 };
        System.out.println("nums1: " + Arrays.toString(a1) + ", nums2: " + Arrays.toString(b1));
        System.out.println("Intersection: " + Arrays.toString(intersect(a1, b1)));

        int[] a2 = { 4, 9, 5 }, b2 = { 9, 4, 9, 8, 4 };
        System.out.println("\nnums1: " + Arrays.toString(a2) + ", nums2: " + Arrays.toString(b2));
        System.out.println("Intersection: " + Arrays.toString(intersect(a2, b2)));
    }
}
