/**
 * Basic DSA Problems - Top K Frequent Elements (LeetCode 347)
 * Return k most frequent elements (any order)
 */
public class basic_dsa_three_hundred_forty_seven {

    // Problem: Array nums, int k. Return k elements that appear most often.

    /**
     * Count frequencies, then bucket sort by frequency (freq -> elements).
     * Time O(n), Space O(n)
     */
    public static int[] topKFrequent(int[] nums, int k) {
        java.util.Map<Integer, Integer> freq = new java.util.HashMap<>();
        for (int x : nums) freq.put(x, freq.getOrDefault(x, 0) + 1);

        @SuppressWarnings("unchecked")
        java.util.List<Integer>[] buckets = new java.util.ArrayList[nums.length + 1];
        for (int i = 0; i < buckets.length; i++) buckets[i] = new java.util.ArrayList<>();
        for (java.util.Map.Entry<Integer, Integer> e : freq.entrySet())
            buckets[e.getValue()].add(e.getKey());

        int[] out = new int[k];
        int j = 0;
        for (int f = nums.length; f >= 1 && j < k; f--)
            for (int x : buckets[f])
                if (j < k) out[j++] = x;
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Top K Frequent Elements");
        System.out.println("=".repeat(60));

        System.out.println("[1,1,1,2,2,3], k=2 -> " + java.util.Arrays.toString(topKFrequent(new int[]{1,1,1,2,2,3}, 2)));
        System.out.println("[1], k=1 -> " + java.util.Arrays.toString(topKFrequent(new int[]{1}, 1)));
    }
}
