/**
 * Basic DSA Problems - One Fundamental Two Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty {

    // Problem 1: Valid Palindrome
    // Consider only letters and digits; ignore case and non-alphanumeric characters.

    /**
     * Two pointers from both ends; skip junk; compare lowercased letters/digits
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean isPalindrome(String s) {
        if (s == null) {
            return null;
        }

        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }
            if (i >= j) {
                break;
            }
            char a = Character.toLowerCase(s.charAt(i));
            char b = Character.toLowerCase(s.charAt(j));
            if (a != b) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Palindrome");
        System.out.println("=".repeat(60));

        System.out.println(
                "phrase -> " + isPalindrome("A man, a plan, a canal: Panama"));
        System.out.println("race a car -> " + isPalindrome("race a car"));
        System.out.println("empty -> " + isPalindrome(""));
        System.out.println("  , .  -> " + isPalindrome("  , .  "));
        System.out.println("null -> " + isPalindrome(null));
    }
}
