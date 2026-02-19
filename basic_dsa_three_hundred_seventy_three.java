/**
 * Basic DSA Problems - Find K Pairs with Smallest Sums (LeetCode 373)
 * Return k pairs (i,j) with smallest nums1[i]+nums2[j]
 */
public class basic_dsa_three_hundred_seventy_three {

    // Problem: Sorted nums1, nums2, k. Return k pairs with smallest sum.

    /**
     * Min-heap of (i,j,sum). Start with (0,0). Expand: add (i+1,j) and (i,j+1).
     * Time O(k log k), Space O(k)
     */
    public static java.util.List<java.util.List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
        if (nums1.length == 0 || nums2.length == 0 || k <= 0) return out;

        java.util.PriorityQueue<int[]> pq = new java.util.PriorityQueue<>(
                (a, b) -> Integer.compare(a[2], b[2]));
        pq.offer(new int[]{0, 0, nums1[0] + nums2[0]});
        java.util.Set<String> seen = new java.util.HashSet<>();
        seen.add("0,0");

        while (!pq.isEmpty() && out.size() < k) {
            int[] cur = pq.poll();
            int i = cur[0], j = cur[1];
            out.add(java.util.Arrays.asList(nums1[i], nums2[j]));
            if (i + 1 < nums1.length && seen.add((i + 1) + "," + j))
                pq.offer(new int[]{i + 1, j, nums1[i + 1] + nums2[j]});
            if (j + 1 < nums2.length && seen.add(i + "," + (j + 1)))
                pq.offer(new int[]{i, j + 1, nums1[i] + nums2[j + 1]});
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find K Pairs with Smallest Sums");
        System.out.println("=".repeat(60));

        System.out.println("nums1=[1,7,11], nums2=[2,4,6], k=3 -> "
                + kSmallestPairs(new int[]{1,7,11}, new int[]{2,4,6}, 3));
    }
}
