/**
 * Basic DSA Problems - One Fundamental Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_nine {
    
    // Problem 1: Valid Parentheses (Stack)
    // Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
    // determine if the input string is valid.
    //
    // A string is valid if:
    // 1) Open brackets must be closed by the same type of brackets.
    // 2) Open brackets must be closed in the correct order.
    
    /**
     * Use a char[] as stack
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean isValid(String s) {
        if (s == null) {
            return null;
        }
        int n = s.length();
        if (n == 0) {
            return true;
        }
        
        char[] stack = new char[n];
        int top = -1;
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack[++top] = c;
            } else if (c == ')' || c == '}' || c == ']') {
                if (top < 0) return false;
                char open = stack[top--];
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '[')) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return top == -1;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Parentheses (Stack)");
        System.out.println("=".repeat(60));
        
        String s1 = "()[]{}";
        System.out.println("Input: " + s1);
        System.out.println("Is Valid: " + isValid(s1));
        
        String s2 = "([)]";
        System.out.println("\nInput: " + s2);
        System.out.println("Is Valid: " + isValid(s2));
        
        String s3 = "{[()()]}";
        System.out.println("\nInput: " + s3);
        System.out.println("Is Valid: " + isValid(s3));
        
        String s4 = "(()";
        System.out.println("\nInput: " + s4);
        System.out.println("Is Valid: " + isValid(s4));
        
        String s5 = "";
        System.out.println("\nInput: \"\"");
        System.out.println("Is Valid: " + isValid(s5));
        
        System.out.println("\nInput: null");
        System.out.println("Is Valid: " + isValid(null));
    }
}

