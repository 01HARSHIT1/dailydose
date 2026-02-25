/**
 * Basic DSA Problems - Ternary Expression Parser (LeetCode 439)
 * Evaluate nested ternary expressions. Right-to-left grouping.
 */
public class basic_dsa_four_hundred_thirty_nine {

    // Problem: "T?2:3" -> "2", "F?1:T?4:5" -> "4"

    /**
     * Process right-to-left. Skip ':'. On '?' next char is condition. Stack: then, else.
     * Time O(n), Space O(n)
     */
    public static String parseTernary(String expression) {
        java.util.Deque<Character> stk = new java.util.ArrayDeque<>();
        boolean cond = false;
        for (int i = expression.length() - 1; i >= 0; i--) {
            char c = expression.charAt(i);
            if (c == ':') continue;
            if (c == '?') cond = true;
            else {
                if (cond) {
                    if (c == 'T') {
                        char x = stk.pop();
                        stk.pop();
                        stk.push(x);
                    } else stk.pop();
                    cond = false;
                } else stk.push(c);
            }
        }
        return String.valueOf(stk.peek());
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Ternary Expression Parser");
        System.out.println("=".repeat(60));

        System.out.println("\"T?2:3\" -> " + parseTernary("T?2:3"));
        System.out.println("\"F?1:T?4:5\" -> " + parseTernary("F?1:T?4:5"));
        System.out.println("\"T?T?F:5:3\" -> " + parseTernary("T?T?F:5:3"));
    }
}
