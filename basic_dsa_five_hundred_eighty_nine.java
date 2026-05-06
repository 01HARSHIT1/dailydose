/**
 * Basic DSA Problems - One Fundamental Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_eighty_nine {

    // Problem 1: Add Binary
    // Given two binary strings a and b, return their sum as a binary string.
    //
    // Example:
    // a = "11", b = "1" -> "100"

    /**
     * Add from right with carry
     * Time Complexity: O(max(n, m))
     * Space Complexity: O(max(n, m))
     */
    public static String addBinary(String a, String b) {
        if (a == null || b == null) {
            return null;
        }

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        StringBuilder sb = new StringBuilder();

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a.charAt(i) - '0';
                i--;
            }
            if (j >= 0) {
                sum += b.charAt(j) - '0';
                j--;
            }
            sb.append(sum % 2);
            carry = sum / 2;
        }

        return sb.reverse().toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Add Binary");
        System.out.println("=".repeat(60));

        System.out.println("\"11\" + \"1\" -> " + addBinary("11", "1"));
        System.out.println("\"1010\" + \"1011\" -> " + addBinary("1010", "1011"));
        System.out.println("\"0\" + \"0\" -> " + addBinary("0", "0"));
        System.out.println("null + \"1\" -> " + addBinary(null, "1"));
    }
}
