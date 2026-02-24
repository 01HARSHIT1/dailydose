/**
 * Basic DSA Problems - Reconstruct Original Digits from English (LeetCode 423)
 * Scrambled letters of digits 0-9 -> output digits in ascending order
 */
public class basic_dsa_four_hundred_twenty_three {

    // Problem: "owoztneoer" -> zero, one, two -> "012"

    /**
     * Unique letters: z->0, w->2, u->4, x->6, g->8. Derive others.
     * Time O(n), Space O(1)
     */
    public static String originalDigits(String s) {
        int[] c = new int[26];
        for (char ch : s.toCharArray()) c[ch - 'a']++;
        int[] cnt = new int[10];
        cnt[0] = c['z' - 'a'];
        cnt[2] = c['w' - 'a'];
        cnt[4] = c['u' - 'a'];
        cnt[6] = c['x' - 'a'];
        cnt[8] = c['g' - 'a'];
        cnt[3] = c['h' - 'a'] - cnt[8];
        cnt[5] = c['f' - 'a'] - cnt[4];
        cnt[7] = c['s' - 'a'] - cnt[6];
        cnt[1] = c['o' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = c['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < cnt[i]; j++) sb.append(i);
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reconstruct Original Digits from English");
        System.out.println("=".repeat(60));

        System.out.println("\"owoztneoer\" -> " + originalDigits("owoztneoer"));
        System.out.println("\"fviefuro\" -> " + originalDigits("fviefuro"));
        System.out.println("\"zerozero\" -> " + originalDigits("zerozero"));
    }
}
