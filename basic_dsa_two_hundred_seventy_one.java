/**
 * Basic DSA Problems - Excel Sheet Column Number
 * Convert column title to number (A=1, Z=26, AA=27, ...)
 */
public class basic_dsa_two_hundred_seventy_one {

    // Problem: "A"->1, "B"->2, ..., "Z"->26, "AA"->27, "AB"->28, etc.
    // Return column number for given title.

    /**
     * Left to right: num = num*26 + (char-'A'+1). Base-26 with offset.
     * Time O(n), Space O(1)
     */
    public static int titleToNumber(String columnTitle) {
        int num = 0;
        for (char c : columnTitle.toCharArray())
            num = num * 26 + (c - 'A' + 1);
        return num;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Excel Sheet Column Number");
        System.out.println("=".repeat(60));

        System.out.println("A -> " + titleToNumber("A"));
        System.out.println("AB -> " + titleToNumber("AB"));
        System.out.println("ZY -> " + titleToNumber("ZY"));
    }
}
