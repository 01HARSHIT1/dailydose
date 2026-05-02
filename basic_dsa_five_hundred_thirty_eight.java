/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_eight {

    // Problem 1: Reverse String
    // Write a function that reverses a character array in-place.
    //
    // Example:
    // s = ['h','e','l','l','o'] -> ['o','l','l','e','h']

    /**
     * Two pointers swapping from both ends
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static char[] reverseString(char[] s) {
        if (s == null) {
            return null;
        }

        int left = 0;
        int right = s.length - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }

    private static String charArrayToString(char[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append("'").append(arr[i]).append("'");
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse String");
        System.out.println("=".repeat(60));

        char[] a1 = {'h', 'e', 'l', 'l', 'o'};
        System.out.println("s = ['h','e','l','l','o'] -> " + charArrayToString(reverseString(a1)));

        char[] a2 = {'H', 'a', 'n', 'n', 'a', 'h'};
        System.out.println("s = ['H','a','n','n','a','h'] -> " + charArrayToString(reverseString(a2)));

        char[] a3 = {};
        System.out.println("s = [] -> " + charArrayToString(reverseString(a3)));

        System.out.println("s = null -> " + charArrayToString(reverseString(null)));
    }
}
