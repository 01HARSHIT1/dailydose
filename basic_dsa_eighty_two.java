/**
 * Basic DSA Problems - Valid Parentheses
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_eighty_two {

    // Problem: Check if a string of brackets is valid.
    // Valid: every opening bracket has a matching closing bracket in correct order.
    // Example: "()[]{}" -> true, "([)]" -> false

    /**
     * Use a stack: push opening brackets, pop and match on closing.
     * Time O(n), Space O(n)
     */
    public static boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0) return false;

        Deque<Character> stack = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                char open = stack.pop();
                if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Parentheses");
        System.out.println("=".repeat(60));

        System.out.println("\"()\" -> " + isValid("()"));
        System.out.println("\"()[]{}\" -> " + isValid("()[]{}"));
        System.out.println("\"(]\" -> " + isValid("(]"));
        System.out.println("\"([)]\" -> " + isValid("([)]"));
        System.out.println("\"{[]}\" -> " + isValid("{[]}"));
        System.out.println("\"\" -> " + isValid(""));
    }
}
