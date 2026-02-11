/**
 * Basic DSA Problems - Ransom Note
 * Check if ransomNote can be constructed from magazine (each char used at most once)
 */
public class basic_dsa_two_hundred_thirty {

    // Problem: Can ransomNote be formed using chars from magazine? Each char use once.

    /**
     * Count chars in magazine; decrement for each char in ransomNote. If any count < 0, false.
     * Time O(m + n), Space O(1) alphabet
     */
    public static boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        for (char c : magazine.toCharArray()) count[c - 'a']++;
        for (char c : ransomNote.toCharArray()) {
            if (--count[c - 'a'] < 0) return false;
        }
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
