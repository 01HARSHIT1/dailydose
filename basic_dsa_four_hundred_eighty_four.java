/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_four {
    
    // Problem 1: Reverse String
    // Given a character array s, reverse the array in-place.
    //
    // Example:
    // s = ['h','e','l','l','o'] -> ['o','l','l','e','h']
    
    /**
     * Two pointers swapping from ends
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void reverseString(char[] s) {
        if (s == null || s.length == 0) {
            return;
        }
        
        int left = 0;
        int right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
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
            if (i > 0) sb.append(", ");
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
        
        char[] s1 = {'h', 'e', 'l', 'l', 'o'};
        System.out.println("Before: " + charArrayToString(s1));
        reverseString(s1);
        System.out.println("After : " + charArrayToString(s1));
        
        char[] s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
        System.out.println("\nBefore: " + charArrayToString(s2));
        reverseString(s2);
        System.out.println("After : " + charArrayToString(s2));
        
        char[] s3 = {};
        System.out.println("\nBefore: " + charArrayToString(s3));
        reverseString(s3);
        System.out.println("After : " + charArrayToString(s3));
        
        char[] s4 = null;
        System.out.println("\nBefore: " + charArrayToString(s4));
        reverseString(s4);
        System.out.println("After : " + charArrayToString(s4));
    }
}

