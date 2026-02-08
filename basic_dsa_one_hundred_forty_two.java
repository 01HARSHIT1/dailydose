/**
 * Basic DSA Problems - Pascal's Triangle II
 * Return the kth row of Pascal's triangle (0-indexed)
 */
import java.util.*;

public class basic_dsa_one_hundred_forty_two {

    // Problem: Return the rowIndex-th row of Pascal's triangle (0-indexed).
    // Use O(rowIndex) extra space. Example: rowIndex=3 -> [1,3,3,1]

    /**
     * Build row in-place from right to left to avoid overwriting.
     * Time O(k^2), Space O(k)
     */
    public static List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for (int i = 1; i <= rowIndex; i++) {
            row.add(1);
            for (int j = i - 1; j >= 1; j--) {
                row.set(j, row.get(j) + row.get(j - 1));
            }
        }
        return row;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Pascal's Triangle II");
        System.out.println("=".repeat(60));

        System.out.println("rowIndex=3 -> " + getRow(3));
        System.out.println("rowIndex=0 -> " + getRow(0));
        System.out.println("rowIndex=4 -> " + getRow(4));
    }
}
