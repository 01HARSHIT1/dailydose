/**
 * Basic DSA Problems - One Fundamental Greedy Mapping Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_nine {

    // Problem 1: Integer to Roman
    // Convert integer num in [1, 3999] to Roman numerals (subtracting pairs included).

    private static final int[] VALUES = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };

    private static final String[] SYMBOLS = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

    /**
     * Greedy: repeatedly take the largest symbol value that fits
     * Time Complexity: O(1) — bounded symbol count per input
     * Space Complexity: O(1) besides output string
     */
    public static String intToRoman(int num) {
        if (num < 1 || num > 3999) {
            return null;
        }

        StringBuilder sb = new StringBuilder();
        int n = num;

        for (int i = 0; i < VALUES.length; i++) {
            while (n >= VALUES[i]) {
                sb.append(SYMBOLS[i]);
                n -= VALUES[i];
            }
        }

        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Integer to Roman");
        System.out.println("=".repeat(60));

        System.out.println("3 -> " + intToRoman(3));
        System.out.println("58 -> " + intToRoman(58));
        System.out.println("1994 -> " + intToRoman(1994));
        System.out.println("3999 -> " + intToRoman(3999));
        System.out.println("0 -> " + intToRoman(0));
    }
}
