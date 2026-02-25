/**
 * Basic DSA Problems - Sort Characters By Frequency (LeetCode 451)
 * Sort string by char frequency descending (same chars grouped together)
 */
public class basic_dsa_four_hundred_fifty_one {

    // Problem: "tree" -> "eert" or "eetr"; "cccaaa" -> "cccaaa" or "aaaccc"

    /**
     * Count freqs, sort chars by freq desc, append each char repeated by count.
     * Time O(n + k log k), Space O(k) where k=unique chars
     */
    public static String frequencySort(String s) {
        int[] cnt = new int[128];
        for (char c : s.toCharArray()) cnt[c]++;
        java.util.List<int[]> list = new java.util.ArrayList<>();
        for (int i = 0; i < 128; i++)
            if (cnt[i] > 0) list.add(new int[]{i, cnt[i]});
        list.sort((a, b) -> Integer.compare(b[1], a[1]));
        StringBuilder sb = new StringBuilder();
        for (int[] p : list)
            for (int i = 0; i < p[1]; i++) sb.append((char) p[0]);
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sort Characters By Frequency");
        System.out.println("=".repeat(60));

        System.out.println("\"tree\" -> " + frequencySort("tree"));
        System.out.println("\"cccaaa\" -> " + frequencySort("cccaaa"));
        System.out.println("\"Aabb\" -> " + frequencySort("Aabb"));
    }
}
