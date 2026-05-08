/**
 * Basic DSA Problems - One Fundamental Parsing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_six {

    // Problem 1: Roman to Integer
    // s is a valid Roman numeral in [1, 3999] using subtractive pairs as in standard notation.

    /**
     * Right-to-left: if current value < previous seen value, subtract; else add
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer romanToInt(String s) {
        if (s == null) {
            return null;
        }

        int sum = 0;
        int prev = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int v = value(s.charAt(i));
            if (v < prev) {
                sum -= v;
            } else {
                sum += v;
                prev = v;
            }
        }

        return sum;
    }

    private static int value(char c) {
        return switch (c) {
            case 'I' -> 1;
            case 'V' -> 5;
            case 'X' -> 10;
            case 'L' -> 50;
            case 'C' -> 100;
            case 'D' -> 500;
            case 'M' -> 1000;
            default -> 0;
        };
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Roman to Integer");
        System.out.println("=".repeat(60));

        System.out.println("III -> " + romanToInt("III"));
        System.out.println("LVIII -> " + romanToInt("LVIII"));
        System.out.println("MCMXCIV -> " + romanToInt("MCMXCIV"));
        System.out.println("IX -> " + romanToInt("IX"));
        System.out.println("null -> " + romanToInt(null));
    }
}
