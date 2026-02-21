/**
 * Basic DSA Problems - Remove K Digits (LeetCode 402)
 * Remove k digits from num to get smallest possible integer
 */
public class basic_dsa_four_hundred_two {

    // Problem: num string, k. Remove k digits. Return smallest result (as string).

    /**
     * Monotonic stack: keep smaller digits. Remove while top > current and k > 0.
     * Time O(n), Space O(n)
     */
    public static String removeKdigits(String num, int k) {
        if (k >= num.length()) return "0";
        java.util.Deque<Character> st = new java.util.ArrayDeque<>();
        for (char c : num.toCharArray()) {
            while (k > 0 && !st.isEmpty() && st.peek() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k-- > 0) st.pop();
        StringBuilder sb = new StringBuilder();
        while (!st.isEmpty()) sb.append(st.pop());
        sb.reverse();
        while (sb.length() > 1 && sb.charAt(0) == '0') sb.deleteCharAt(0);
        return sb.length() == 0 ? "0" : sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove K Digits");
        System.out.println("=".repeat(60));

        System.out.println("1432219, k=3 -> " + removeKdigits("1432219", 3));
        System.out.println("10200, k=1 -> " + removeKdigits("10200", 1));
    }
}
