/**
 * Basic DSA Problems - Decode String
 * Decode k[encoded_string] repeated k times
 */
import java.util.*;

public class basic_dsa_one_hundred_thirty {

    // Problem: s = "3[a]2[bc]" -> "aaabcbc", "3[a2[c]]" -> "accaccacc". k is positive integer.

    /**
     * Two stacks: one for counts, one for string builders. On '[', push count and new builder;
     * on ']', pop, repeat and append to previous builder.
     * Time O(maxK * n), Space O(n)
     */
    public static String decodeString(String s) {
        if (s == null || s.isEmpty()) return "";
        Deque<Integer> countStack = new ArrayDeque<>();
        Deque<StringBuilder> strStack = new ArrayDeque<>();
        strStack.push(new StringBuilder());
        int k = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) k = k * 10 + (c - '0');
            else if (c == '[') {
                countStack.push(k);
                k = 0;
                strStack.push(new StringBuilder());
            } else if (c == ']') {
                StringBuilder sb = strStack.pop();
                int repeat = countStack.pop();
                String part = sb.toString();
                for (int i = 1; i < repeat; i++) sb.append(part);
                strStack.peek().append(sb);
            } else strStack.peek().append(c);
        }
        return strStack.pop().toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Decode String");
        System.out.println("=".repeat(60));

        System.out.println("3[a]2[bc] -> " + decodeString("3[a]2[bc]"));
        System.out.println("3[a2[c]] -> " + decodeString("3[a2[c]]"));
    }
}
