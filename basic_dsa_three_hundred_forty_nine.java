/**
 * Basic DSA Problems - Intersection of Two Arrays (LeetCode 349)
 * Return unique elements present in both arrays
 */
public class basic_dsa_three_hundred_forty_nine {

    // Problem: Two arrays. Return intersection (unique elements in both).

    /**
     * Put nums1 in set, collect from nums2 if in set, dedupe.
     * Time O(m+n), Space O(m)
     */
    public static int[] intersection(int[] nums1, int[] nums2) {
        java.util.Set<Integer> set = new java.util.HashSet<>();
        for (int x : nums1) set.add(x);
        java.util.Set<Integer> out = new java.util.HashSet<>();
        for (int x : nums2) if (set.contains(x)) out.add(x);
        return out.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Intersection of Two Arrays");
        System.out.println("=".repeat(60));

        System.out.println("nums1=[1,2,2,1], nums2=[2,2] -> " + java.util.Arrays.toString(intersection(new int[]{1,2,2,1}, new int[]{2,2})));
        System.out.println("nums1=[4,9,5], nums2=[9,4,9,8,4] -> " + java.util.Arrays.toString(intersection(new int[]{4,9,5}, new int[]{9,4,9,8,4})));
    }
}
