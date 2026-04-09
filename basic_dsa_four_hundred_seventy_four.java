/**
 * Basic DSA Problems - One Fundamental String Parsing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_four {

    // Problem 1: Roman to Integer
    // Convert a Roman numeral string to an integer. Roman numerals are usually written largest to
    // smallest left to right. When a smaller value appears before a larger one, subtract it
    // (e.g., IV = 4, IX = 9).
    //
    // Example:
    // "III" -> 3
    // "LVIII" -> 58
    // "MCMXCIV" -> 1994

    private static int value(char c) {
        return switch (c) {
            case 'I' -> 1;
            case 'V' -> 5;
            case 'X' -> 10;
            case 'L' -> 50;
            case 'C' -> 100;
            case 'D' -> 500;
            case 'M' -> 1000;
            default -> -1;
        };
    }

    /**
     * One left-to-right pass: if current < next, subtract current; else add current
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer romanToInt(String s) {
        if (s == null || s.isEmpty()) {
            return null;
        }

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int v = value(s.charAt(i));
            if (v < 0) {
                return null;
            }
            if (i + 1 < n) {
                int next = value(s.charAt(i + 1));
                if (next < 0) {
                    return null;
                }
                if (v < next) {
                    total -= v;
                } else {
                    total += v;
                }
            } else {
                total += v;
            }
        }

        return total;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Roman to Integer");
        System.out.println("=".repeat(60));

        System.out.println("III       -> " + romanToInt("III"));
        System.out.println("LVIII     -> " + romanToInt("LVIII"));
        System.out.println("MCMXCIV   -> " + romanToInt("MCMXCIV"));
        System.out.println("IX        -> " + romanToInt("IX"));
        System.out.println("XL        -> " + romanToInt("XL"));

        System.out.println("\n\"\"        -> " + romanToInt(""));
        System.out.println("null      -> " + romanToInt(null));
        System.out.println("ABC       -> " + romanToInt("ABC"));
    }
}
