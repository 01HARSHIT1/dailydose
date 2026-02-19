/**
 * Basic DSA Problems - Rearrange String k Distance Apart (LeetCode 358)
 * Rearrange so same chars are at least k apart
 */
public class basic_dsa_three_hundred_fifty_eight {

    // Problem: String s, int k. Rearrange so identical chars are >= k apart. Return "" if impossible.

    /**
     * Greedy: pick most frequent char that is available (not in last k).
     * Queue tracks (char, count, nextSlot) - return to heap when nextSlot <= i.
     * Time O(n log 26), Space O(n)
     */
    public static String rearrangeString(String s, int k) {
        if (k <= 1) return s;
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        java.util.PriorityQueue<int[]> pq = new java.util.PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0) pq.offer(new int[]{i, freq[i], 0});
        java.util.Queue<int[]> cooldown = new java.util.LinkedList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            while (!cooldown.isEmpty() && cooldown.peek()[2] <= i) pq.offer(cooldown.poll());
            if (pq.isEmpty()) return "";
            int[] cur = pq.poll();
            sb.append((char) ('a' + cur[0]));
            cur[1]--;
            if (cur[1] > 0) {
                cur[2] = i + k;
                cooldown.offer(cur);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Rearrange String k Distance Apart");
        System.out.println("=".repeat(60));

        System.out.println("aabbcc, k=3 -> " + rearrangeString("aabbcc", 3));
        System.out.println("aaabc, k=3 -> " + rearrangeString("aaabc", 3));
    }
}
