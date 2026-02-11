/**
 * Basic DSA Problems - Integer to Roman
 * Convert integer to Roman numeral (1 <= num <= 3999)
 */
public class basic_dsa_two_hundred_eighteen {

    // Problem: Convert integer to Roman numeral. Symbols: I,V,X,L,C,D,M.

    private static final int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private static final String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    /**
     * Greedy: subtract largest possible value and append corresponding symbol.
     * Time O(1), Space O(1)
     */
    public static String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                num -= values[i];
                sb.append(symbols[i]);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Integer to Roman");
        System.out.println("=".repeat(60));

        System.out.println("3 -> " + intToRoman(3));
        System.out.println("58 -> " + intToRoman(58));
        System.out.println("1994 -> " + intToRoman(1994));
    }
}
