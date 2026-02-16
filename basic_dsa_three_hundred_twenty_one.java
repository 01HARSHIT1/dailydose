/**
 * Basic DSA Problems - String to Integer (atoi)
 * Parse string to integer with overflow handling
 */
public class basic_dsa_three_hundred_twenty_one {

    // Problem: Parse leading integer from string. Handle +/-, leading spaces, overflow.

    /**
     * Skip spaces, read sign, accumulate digits. Clamp to [Integer.MIN_VALUE, Integer.MAX_VALUE].
     * Time O(n), Space O(1)
     */
    public static int myAtoi(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == ' ') i++;
        if (i >= s.length()) return 0;
        int sign = 1;
        if (s.charAt(i) == '-') { sign = -1; i++; }
        else if (s.charAt(i) == '+') i++;
        long val = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            val = val * 10 + (s.charAt(i++) - '0');
            if (val * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (val * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return (int) (val * sign);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: String to Integer (atoi)");
        System.out.println("=".repeat(60));

        System.out.println("\"42\" -> " + myAtoi("42"));
        System.out.println("\"   -42\" -> " + myAtoi("   -42"));
        System.out.println("\"4193 with words\" -> " + myAtoi("4193 with words"));
    }
}
