/**
 * Basic DSA Problems - Intersection of Two Arrays II
 * Return intersection (each element as many times as it appears in both)
 */
import java.util.*;

public class basic_dsa_one_hundred_sixteen {

    // Problem: Given two integer arrays, return an array of their intersection. Each element
    // in the result must appear as many times as it shows in both arrays (any order).

    /**
     * Count frequency in first array; for second array, add to result when count > 0 and decrement.
     * Time O(m+n), Space O(min(m,n))
     */
    public static int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) return new int[0];
        if (nums1.length > nums2.length) return intersect(nums2, nums1); // use smaller for map
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : nums1) freq.put(x, freq.getOrDefault(x, 0) + 1);
        List<Integer> list = new ArrayList<>();
        for (int x : nums2) {
            int c = freq.getOrDefault(x, 0);
            if (c > 0) {
                list.add(x);
                freq.put(x, c - 1);
            }
        }
        return list.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Intersection of Two Arrays II");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,2,1] & [2,2] -> " + Arrays.toString(intersect(new int[] { 1, 2, 2, 1 }, new int[] { 2, 2 })));
        System.out.println("[4,9,5] & [9,4,9,8,4] -> " + Arrays.toString(intersect(new int[] { 4, 9, 5 }, new int[] { 9, 4, 9, 8, 4 })));
    }
}
