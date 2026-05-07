/**
 * Basic DSA Problems - One Fundamental Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_ninety_three {

    // Problem 1: Valid Parentheses
    // Given a string s containing only '(', ')', '{', '}', '[' and ']',
    // determine if the input string is valid:
    // - Open brackets must be closed by the same type of brackets.
    // - Open brackets must be closed in the correct order.
    // - Every close bracket has a matching open bracket.

    /**
     * Monotonic stack of unmatched opening brackets
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean isValid(String s) {
        if (s == null) {
            return null;
        }

        char[] stack = new char[s.length()];
        int top = -1;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack[++top] = c;
            } else if (c == ')' || c == ']' || c == '}') {
                if (top < 0) {
                    return false;
                }
                char open = stack[top--];
                if (!matches(open, c)) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return top == -1;
    }

    private static boolean matches(char open, char close) {
        return (open == '(' && close == ')')
                || (open == '[' && close == ']')
                || (open == '{' && close == '}');
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Parentheses");
        System.out.println("=".repeat(60));

        System.out.println("\"()\" -> " + isValid("()"));
        System.out.println("\"()[]{}\" -> " + isValid("()[]{}"));
        System.out.println("\"(]\" -> " + isValid("(]"));
        System.out.println("\"([)]\" -> " + isValid("([)]"));
        System.out.println("\"{[]}\" -> " + isValid("{[]}"));
        System.out.println("\"\" -> " + isValid(""));
        System.out.println("null -> " + isValid(null));
    }
}
