/**
 * Basic DSA Problems - One Fundamental Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_six {

    // Problem 1: Backspace String Compare
    // Given two strings s and t, return true if they are equal when both are typed into
    // empty text editors. '#' means a backspace character.
    //
    // Example:
    // s = "ab#c", t = "ad#c" -> true

    /**
     * Build final strings using StringBuilder as stack
     * Time Complexity: O(n + m)
     * Space Complexity: O(n + m)
     */
    public static Boolean backspaceCompare(String s, String t) {
        if (s == null || t == null) {
            return null;
        }
        return buildTyped(s).equals(buildTyped(t));
    }

    private static String buildTyped(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '#') {
                if (sb.length() > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                }
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Backspace String Compare");
        System.out.println("=".repeat(60));

        System.out.println("s = \"ab#c\", t = \"ad#c\" -> " + backspaceCompare("ab#c", "ad#c"));
        System.out.println("s = \"ab##\", t = \"c#d#\" -> " + backspaceCompare("ab##", "c#d#"));
        System.out.println("s = \"a##c\", t = \"#a#c\" -> " + backspaceCompare("a##c", "#a#c"));
        System.out.println("s = \"a#c\", t = \"b\" -> " + backspaceCompare("a#c", "b"));
        System.out.println("s = null, t = \"a\" -> " + backspaceCompare(null, "a"));
    }
}
