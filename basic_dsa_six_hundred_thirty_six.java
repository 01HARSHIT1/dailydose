/**
 * Basic DSA Problems - One Fundamental Radix / String Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_six {

    // Problem 1: Excel Sheet Column Number
    // columnTitle is like "A".."Z", "AA", "AB", ... Map to 1-based integer (A=1, Z=26, AA=27).

    /**
     * Base-26 from left: result = result * 26 + (letter value)
     * Time Complexity: O(k) for title length k
     * Space Complexity: O(1)
     */
    public static Integer titleToNumber(String columnTitle) {
        if (columnTitle == null) {
            return null;
        }

        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            int v = columnTitle.charAt(i) - 'A' + 1;
            result = result * 26 + v;
        }

        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Excel Sheet Column Number");
        System.out.println("=".repeat(60));

        System.out.println("A -> " + titleToNumber("A"));
        System.out.println("AB -> " + titleToNumber("AB"));
        System.out.println("ZY -> " + titleToNumber("ZY"));
        System.out.println("FXSHRXW -> " + titleToNumber("FXSHRXW"));
        System.out.println("null -> " + titleToNumber(null));
    }
}
