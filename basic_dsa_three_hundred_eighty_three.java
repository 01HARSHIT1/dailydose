/**
 * Basic DSA Problems - Ransom Note (LeetCode 383)
 * Can ransomNote be formed from magazine letters? Each letter used once.
 */
public class basic_dsa_three_hundred_eighty_three {

    // Problem: ransomNote, magazine. Return true if ransomNote can be built from magazine.

    /**
     * Count magazine chars, decrement for each ransom char. Fail if any go negative.
     * Time O(m+n), Space O(1)
     */
    public static boolean canConstruct(String ransomNote, String magazine) {
        int[] freq = new int[26];
        for (char c : magazine.toCharArray()) freq[c - 'a']++;
        for (char c : ransomNote.toCharArray())
            if (--freq[c - 'a'] < 0) return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Ransom Note");
        System.out.println("=".repeat(60));

        System.out.println("a, b -> " + canConstruct("a", "b"));
        System.out.println("aa, ab -> " + canConstruct("aa", "ab"));
        System.out.println("aa, aab -> " + canConstruct("aa", "aab"));
    }
}
