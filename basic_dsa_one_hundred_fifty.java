/**
 * Basic DSA Problems - Base 7
 * Convert integer to base 7 string
 */
public class basic_dsa_one_hundred_fifty {

    // Problem: Given an integer num, return its string representation in base 7.
    // Example: 100 -> "202", -7 -> "-10"

    /**
     * Convert by repeatedly dividing by 7, collecting remainders
     * Time O(log n), Space O(log n) for output
     */
    public static String convertToBase7(int num) {
        if (num == 0) return "0";
        boolean neg = num < 0;
        num = Math.abs(num);
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % 7);
            num /= 7;
        }
        if (neg) sb.append('-');
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Base 7");
        System.out.println("=".repeat(60));

        System.out.println("100 -> " + convertToBase7(100));
        System.out.println("-7 -> " + convertToBase7(-7));
        System.out.println("0 -> " + convertToBase7(0));
        System.out.println("7 -> " + convertToBase7(7));
    }
}
