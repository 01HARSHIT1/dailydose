/**
 * Basic DSA Problems - Ransom Note
 * Check if ransom note can be constructed from magazine
 */
public class basic_dsa_two_hundred_forty {

    // Problem: Given ransomNote and magazine, return true if ransomNote can be built
    // using letters from magazine. Each letter in magazine can be used only once.

    /**
     * Count magazine chars, decrement for ransomNote. If any go negative, return false.
     * Time O(m+n), Space O(1) - 26 chars
     */
    public static boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        for (int i = 0; i < magazine.length(); i++)
            count[magazine.charAt(i) - 'a']++;
        for (int i = 0; i < ransomNote.length(); i++) {
            int c = ransomNote.charAt(i) - 'a';
            count[c]--;
            if (count[c] < 0) return false;
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
