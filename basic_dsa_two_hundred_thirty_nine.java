/**
 * Basic DSA Problems - Intersection of Two Arrays II
 * Find intersection of two arrays (allow duplicates)
 */
public class basic_dsa_two_hundred_thirty_nine {

    // Problem: Given nums1 and nums2, return array of elements that appear in both.
    // Each element in result should appear as many times as in both arrays.

    /**
     * Count freq in nums1, decrement for nums2 when found, collect.
     * Time O(m+n), Space O(min(m,n)) for result
     */
    public static int[] intersect(int[] nums1, int[] nums2) {
        int[] count = new int[1001];
        for (int x : nums1) count[x]++;
        java.util.List<Integer> list = new java.util.ArrayList<>();
        for (int x : nums2) {
            if (count[x] > 0) {
                list.add(x);
                count[x]--;
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

        int[] a = intersect(new int[]{1, 2, 2, 1}, new int[]{2, 2});
        System.out.println("[1,2,2,1] ∩ [2,2] -> " + java.util.Arrays.toString(a));

        int[] b = intersect(new int[]{4, 9, 5}, new int[]{9, 4, 9, 8, 4});
        System.out.println("[4,9,5] ∩ [9,4,9,8,4] -> " + java.util.Arrays.toString(b));
    }
}
