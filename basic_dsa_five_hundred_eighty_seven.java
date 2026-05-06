/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_seven {

    // Problem 1: To Lower Case
    // Implement a function to convert a string to lowercase without built-in toLowerCase.
    // Only English letters and ASCII; other characters unchanged.
    //
    // Example:
    // s = "Hello" -> "hello"

    /**
     * Map A-Z to a-z by adding 32
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String toLowerCaseManual(String s) {
        if (s == null) {
            return null;
        }
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] >= 'A' && chars[i] <= 'Z') {
                chars[i] = (char) (chars[i] - 'A' + 'a');
            }
        }
        return new String(chars);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: To Lower Case");
        System.out.println("=".repeat(60));

        System.out.println("\"Hello\" -> " + toLowerCaseManual("Hello"));
        System.out.println("\"here\" -> " + toLowerCaseManual("here"));
        System.out.println("\"LOVELY\" -> " + toLowerCaseManual("LOVELY"));
        System.out.println("\"A1b!C\" -> " + toLowerCaseManual("A1b!C"));
        System.out.println("null -> " + toLowerCaseManual(null));
    }
}
