/**
 * Basic DSA Problems - One Fundamental Two Pointers Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_one {

    // Problem 1: Reverse String II
    // Given a string s and an integer k, reverse the first k characters
    // for every 2k characters counting from the start of the string.
    //
    // Example:
    // s = "abcdefg", k = 2 -> "bacdfeg"

    /**
     * Process string in blocks of 2k and reverse first k in each block
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String reverseStr(String s, int k) {
        if (s == null || k <= 0) {
            return null;
        }

        char[] chars = s.toCharArray();
        for (int start = 0; start < chars.length; start += 2 * k) {
            int left = start;
            int right = Math.min(start + k - 1, chars.length - 1);
            while (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }

        return new String(chars);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse String II");
        System.out.println("=".repeat(60));

        System.out.println("s = \"abcdefg\", k = 2 -> " + reverseStr("abcdefg", 2));
        System.out.println("s = \"abcd\", k = 2 -> " + reverseStr("abcd", 2));
        System.out.println("s = \"a\", k = 2 -> " + reverseStr("a", 2));
        System.out.println("s = \"abcdef\", k = 3 -> " + reverseStr("abcdef", 3));
        System.out.println("s = null, k = 2 -> " + reverseStr(null, 2));
    }
}
