/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_four {

    // Problem 1: Reverse Words in a String III
    // Given a string s, reverse the order of characters in each word within a sentence
    // while still preserving whitespace and initial word order.
    //
    // Example:
    // s = "Let's take LeetCode contest" -> "s'teL ekat edoCteeL tsetnoc"

    /**
     * Reverse each word independently using two pointers
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static String reverseWords(String s) {
        if (s == null) {
            return null;
        }

        char[] chars = s.toCharArray();
        int start = 0;
        for (int i = 0; i <= chars.length; i++) {
            if (i == chars.length || chars[i] == ' ') {
                reverse(chars, start, i - 1);
                start = i + 1;
            }
        }
        return new String(chars);
    }

    private static void reverse(char[] arr, int left, int right) {
        while (left < right) {
            char tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse Words in a String III");
        System.out.println("=".repeat(60));

        System.out.println("s = \"Let's take LeetCode contest\" -> " + reverseWords("Let's take LeetCode contest"));
        System.out.println("s = \"God Ding\" -> " + reverseWords("God Ding"));
        System.out.println("s = \"a\" -> " + reverseWords("a"));
        System.out.println("s = \"\" -> " + reverseWords(""));
        System.out.println("s = null -> " + reverseWords(null));
    }
}
