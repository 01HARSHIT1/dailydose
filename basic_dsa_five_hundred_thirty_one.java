/**
 * Basic DSA Problems - One Fundamental Two Pointers Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_one {

    // Problem 1: Valid Palindrome
    // Given a string s, determine if it is a palindrome, considering only alphanumeric characters
    // and ignoring cases.
    //
    // Example:
    // s = "A man, a plan, a canal: Panama" -> true
    // s = "race a car" -> false

    /**
     * Two pointers from both ends with character filtering
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean isPalindrome(String s) {
        if (s == null) {
            return null;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            char lc = s.charAt(left);
            char rc = s.charAt(right);

            if (!Character.isLetterOrDigit(lc)) {
                left++;
                continue;
            }
            if (!Character.isLetterOrDigit(rc)) {
                right--;
                continue;
            }

            if (Character.toLowerCase(lc) != Character.toLowerCase(rc)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Palindrome");
        System.out.println("=".repeat(60));

        System.out.println("\"A man, a plan, a canal: Panama\" -> "
                + isPalindrome("A man, a plan, a canal: Panama"));
        System.out.println("\"race a car\" -> " + isPalindrome("race a car"));
        System.out.println("\" \" -> " + isPalindrome(" "));
        System.out.println("\"No 'x' in Nixon\" -> " + isPalindrome("No 'x' in Nixon"));
        System.out.println("null -> " + isPalindrome(null));
    }
}
