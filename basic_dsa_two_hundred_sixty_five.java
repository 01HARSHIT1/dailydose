/**
 * Basic DSA Problems - Word Pattern
 * Check if string follows a character pattern
 */
public class basic_dsa_two_hundred_sixty_five {

    // Problem: pattern "abba", s "dog cat cat dog". Return true if s follows pattern.
    // Bijection: each letter maps to exactly one word, each word to one letter.

    /**
     * Split s into words. Check length matches. Use two maps for bijection.
     * Time O(n), Space O(w) where w = distinct words
     */
    public static boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        java.util.Map<Character, String> cToW = new java.util.HashMap<>();
        java.util.Map<String, Character> wToC = new java.util.HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (cToW.containsKey(c) && !cToW.get(c).equals(w)) return false;
            if (wToC.containsKey(w) && wToC.get(w) != c) return false;
            cToW.put(c, w);
            wToC.put(w, c);
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Word Pattern");
        System.out.println("=".repeat(60));

        System.out.println("abba, dog cat cat dog -> " + wordPattern("abba", "dog cat cat dog"));
        System.out.println("abba, dog cat cat fish -> " + wordPattern("abba", "dog cat cat fish"));
        System.out.println("aaaa, dog cat cat dog -> " + wordPattern("aaaa", "dog cat cat dog"));
    }
}
