/**
 * Basic DSA Problems - Zigzag Conversion
 * Arrange string in zigzag pattern and read by rows
 */
public class basic_dsa_three_hundred_twenty_two {

    // Problem: String s and numRows. Write in zigzag pattern (like diagonal rows), return row-by-row string.

    /**
     * Track row index with direction; append each char to its row. Concatenate rows.
     * Time O(n), Space O(n)
     */
    public static String convert(String s, int numRows) {
        if (numRows == 1) return s;
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) rows[i] = new StringBuilder();
        int row = 0, dir = 1;
        for (char c : s.toCharArray()) {
            rows[row].append(c);
            row += dir;
            if (row == 0 || row == numRows - 1) dir = -dir;
        }
        return String.join("", rows);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Zigzag Conversion");
        System.out.println("=".repeat(60));

        System.out.println("PAYPALISHIRING, 3 -> " + convert("PAYPALISHIRING", 3));
        System.out.println("PAYPALISHIRING, 4 -> " + convert("PAYPALISHIRING", 4));
        System.out.println("A, 1 -> " + convert("A", 1));
    }
}
