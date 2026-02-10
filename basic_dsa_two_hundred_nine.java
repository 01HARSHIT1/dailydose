/**
 * Basic DSA Problems - Word Pattern
 * Check if string s follows the pattern (bijection between pattern chars and words)
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_two_hundred_nine {

    // Problem: pattern = "abba", s = "dog cat cat dog". Return true if s follows pattern.

    /**
     * Map char -> word and set of seen words. Each char must map to same word; each word to same char.
     * Time O(n), Space O(n)
     */
    public static boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        Map<Character, String> charToWord = new HashMap<>();
        Map<String, Character> wordToChar = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (charToWord.containsKey(c) && !charToWord.get(c).equals(w)) return false;
            if (wordToChar.containsKey(w) && wordToChar.get(w) != c) return false;
            charToWord.put(c, w);
            wordToChar.put(w, c);
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
