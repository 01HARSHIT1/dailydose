/**
 * Basic DSA Problems - Convert a Number to Hexadecimal (LeetCode 405)
 * Convert integer to hex string (lowercase, no leading 0s)
 */
public class basic_dsa_four_hundred_five {

    // Problem: num to hex. Negative uses two's complement. No leading zeros.

    private static final char[] HEX = "0123456789abcdef".toCharArray();

    /**
     * Extract nibbles from right. Use unsigned right shift to handle negative.
     * Time O(8), Space O(1)
     */
    public static String toHex(int num) {
        if (num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        long n = num & 0xFFFFFFFFL;
        while (n > 0) {
            sb.append(HEX[(int) (n % 16)]);
            n /= 16;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Convert a Number to Hexadecimal");
        System.out.println("=".repeat(60));

        System.out.println("26 -> " + toHex(26));
        System.out.println("-1 -> " + toHex(-1));
    }
}
