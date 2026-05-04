/**
 * Basic DSA Problems - One Fundamental Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_five {

    // Problem 1: Word Pattern
    // Given a pattern and a string s, find if s follows the same pattern.
    // A bijection must exist between a letter in pattern and a non-empty word in s.
    //
    // Example:
    // pattern = "abba", s = "dog cat cat dog" -> true

    /**
     * Bidirectional map validation
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean wordPattern(String pattern, String s) {
        if (pattern == null || s == null) {
            return null;
        }

        String[] words = s.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }

        java.util.HashMap<Character, String> mapPS = new java.util.HashMap<>();
        java.util.HashMap<String, Character> mapSP = new java.util.HashMap<>();

        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            String w = words[i];

            String mappedWord = mapPS.get(p);
            Character mappedChar = mapSP.get(w);

            if (mappedWord != null && !mappedWord.equals(w)) {
                return false;
            }
            if (mappedChar != null && mappedChar != p) {
                return false;
            }

            mapPS.put(p, w);
            mapSP.put(w, p);
        }

        return true;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Word Pattern");
        System.out.println("=".repeat(60));

        System.out.println("pattern = \"abba\", s = \"dog cat cat dog\" -> " + wordPattern("abba", "dog cat cat dog"));
        System.out.println("pattern = \"abba\", s = \"dog cat cat fish\" -> " + wordPattern("abba", "dog cat cat fish"));
        System.out.println("pattern = \"aaaa\", s = \"dog cat cat dog\" -> " + wordPattern("aaaa", "dog cat cat dog"));
        System.out.println("pattern = \"abba\", s = \"dog dog dog dog\" -> " + wordPattern("abba", "dog dog dog dog"));
        System.out.println("pattern = null, s = \"dog cat\" -> " + wordPattern(null, "dog cat"));
    }
}
