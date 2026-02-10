/**
 * Basic DSA Problems - Top K Frequent Elements
 * Return k most frequent elements (order doesn't matter)
 */
import java.util.*;

public class basic_dsa_two_hundred_one {

    // Problem: Array nums and integer k. Return the k most frequent elements.

    /**
     * Count frequencies, bucket sort: bucket[i] = list of elements with frequency i. Collect from high freq.
     * Time O(n), Space O(n)
     */
    public static int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums) count.put(x, count.getOrDefault(x, 0) + 1);
        List<Integer>[] buckets = new List[nums.length + 1];
        for (int i = 0; i < buckets.length; i++) buckets[i] = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : count.entrySet())
            buckets[e.getValue()].add(e.getKey());
        int[] out = new int[k];
        int idx = 0;
        for (int f = nums.length; f >= 1 && idx < k; f--)
            for (int x : buckets[f])
                if (idx < k) out[idx++] = x;
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Top K Frequent Elements");
        System.out.println("=".repeat(60));

        System.out.println("nums=[1,1,1,2,2,3], k=2 -> " + Arrays.toString(topKFrequent(new int[]{1, 1, 1, 2, 2, 3}, 2)));
        System.out.println("nums=[1], k=1 -> " + Arrays.toString(topKFrequent(new int[]{1}, 1)));
    }
}
