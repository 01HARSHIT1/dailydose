/**
 * Basic DSA Problems - Valid Parentheses
 * Check if string of brackets is valid (every open has a matching close in order)
 */
import java.util.ArrayDeque;
import java.util.Deque;

public class basic_dsa_one_hundred_ninety_five {

    // Problem: String s containing '()', '[]', '{}'. Return true if valid.

    /**
     * Stack: push opening; on closing, pop and check match. Stack must be empty at end.
     * Time O(n), Space O(n)
     */
    public static boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{')
                stack.push(c);
            else {
                if (stack.isEmpty()) return false;
                char open = stack.pop();
                if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{'))
                    return false;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Parentheses");
        System.out.println("=".repeat(60));

        System.out.println("() -> " + isValid("()"));
        System.out.println("()[]{} -> " + isValid("()[]{}"));
        System.out.println("(] -> " + isValid("(]"));
        System.out.println("([)] -> " + isValid("([)]"));
    }
}
