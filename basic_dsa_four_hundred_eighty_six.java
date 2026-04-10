/**
 * Basic DSA Problems - One Fundamental String Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_six {
    
    // Problem 1: Valid Palindrome
    // Given a string s, determine if it is a palindrome, considering only alphanumeric characters
    // and ignoring cases.
    //
    // Example:
    // "A man, a plan, a canal: Panama" -> true
    // "race a car" -> false
    
    /**
     * Two pointers skipping non-alphanumeric characters
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
            char cl = s.charAt(left);
            char cr = s.charAt(right);
            
            while (left < right && !Character.isLetterOrDigit(cl)) {
                left++;
                cl = s.charAt(left);
            }
            while (left < right && !Character.isLetterOrDigit(cr)) {
                right--;
                cr = s.charAt(right);
            }
            
            if (Character.toLowerCase(cl) != Character.toLowerCase(cr)) {
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
        
        String s1 = "A man, a plan, a canal: Panama";
        System.out.println("Input: " + s1);
        System.out.println("Is Palindrome: " + isPalindrome(s1));
        
        String s2 = "race a car";
        System.out.println("\nInput: " + s2);
        System.out.println("Is Palindrome: " + isPalindrome(s2));
        
        String s3 = " ";
        System.out.println("\nInput: \" \"");
        System.out.println("Is Palindrome: " + isPalindrome(s3));
        
        String s4 = "0P";
        System.out.println("\nInput: " + s4);
        System.out.println("Is Palindrome: " + isPalindrome(s4));
        
        String s5 = "";
        System.out.println("\nInput: \"\"");
        System.out.println("Is Palindrome: " + isPalindrome(s5));
        
        System.out.println("\nInput: null");
        System.out.println("Is Palindrome: " + isPalindrome(null));
    }
}

