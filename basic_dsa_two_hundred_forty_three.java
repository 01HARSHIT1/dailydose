/**
 * Basic DSA Problems - Add Strings
 * Add two non-negative integers represented as strings
 */
public class basic_dsa_two_hundred_forty_three {

    // Problem: num1 and num2 are non-negative integers as strings. Return their sum as string.
    // No BigInteger; handle arbitrarily large numbers.

    /**
     * School addition: process from right to left with carry.
     * Time O(max(m,n)), Space O(max(m,n))
     */
    public static String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int a = i >= 0 ? num1.charAt(i--) - '0' : 0;
            int b = j >= 0 ? num2.charAt(j--) - '0' : 0;
            int sum = a + b + carry;
            sb.append(sum % 10);
            carry = sum / 10;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Add Strings");
        System.out.println("=".repeat(60));

        System.out.println("11 + 123 -> " + addStrings("11", "123"));
        System.out.println("456 + 77 -> " + addStrings("456", "77"));
        System.out.println("0 + 0 -> " + addStrings("0", "0"));
    }
}
