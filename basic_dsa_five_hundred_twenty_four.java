/**
 * Basic DSA Problems - One Fundamental Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_four {

    // Problem 1: Valid Parentheses
    // Given a string containing just '(', ')', '{', '}', '[' and ']',
    // determine if the input string is valid.
    //
    // A string is valid if:
    // 1) Open brackets are closed by the same type of brackets.
    // 2) Open brackets are closed in the correct order.
    //
    // Example:
    // s = "()[]{}" -> true
    // s = "(]"     -> false

    /**
     * Stack-based bracket matching
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean isValidParentheses(String s) {
        if (s == null) {
            return null;
        }

        char[] stack = new char[s.length()];
        int top = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '(' || ch == '[' || ch == '{') {
                stack[++top] = ch;
            } else {
                if (top == -1) {
                    return false;
                }

                char open = stack[top--];
                if ((ch == ')' && open != '(')
                        || (ch == ']' && open != '[')
                        || (ch == '}' && open != '{')) {
                    return false;
                }
            }
        }

        return top == -1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Parentheses");
        System.out.println("=".repeat(60));

        System.out.println("s = \"()\" -> " + isValidParentheses("()"));
        System.out.println("s = \"()[]{}\" -> " + isValidParentheses("()[]{}"));
        System.out.println("s = \"(]\" -> " + isValidParentheses("(]"));
        System.out.println("s = \"([)]\" -> " + isValidParentheses("([)]"));
        System.out.println("s = \"{[]}\" -> " + isValidParentheses("{[]}"));
        System.out.println("s = \"\" -> " + isValidParentheses(""));
        System.out.println("s = null -> " + isValidParentheses(null));
    }
}
