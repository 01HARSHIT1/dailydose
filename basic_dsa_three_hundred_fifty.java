/**
 * Basic DSA Problems - Intersection of Two Arrays II (LeetCode 350)
 * Return intersection with multiplicity (each appears min of counts in both)
 */
public class basic_dsa_three_hundred_fifty {

    // Problem: Two arrays. Return intersection, each appearing min(count1, count2) times.

    /**
     * Count nums1, decrement for each in nums2 when count > 0, add to result.
     * Time O(m+n), Space O(min(m,n))
     */
    public static int[] intersect(int[] nums1, int[] nums2) {
        java.util.Map<Integer, Integer> freq = new java.util.HashMap<>();
        for (int x : nums1) freq.put(x, freq.getOrDefault(x, 0) + 1);
        java.util.List<Integer> out = new java.util.ArrayList<>();
        for (int x : nums2) {
            int c = freq.getOrDefault(x, 0);
            if (c > 0) {
                out.add(x);
                freq.put(x, c - 1);
            }
        }
        return out.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Intersection of Two Arrays II");
        System.out.println("=".repeat(60));

        System.out.println("nums1=[1,2,2,1], nums2=[2,2] -> " + java.util.Arrays.toString(intersect(new int[]{1,2,2,1}, new int[]{2,2})));
        System.out.println("nums1=[4,9,5], nums2=[9,4,9,8,4] -> " + java.util.Arrays.toString(intersect(new int[]{4,9,5}, new int[]{9,4,9,8,4})));
    }
}
