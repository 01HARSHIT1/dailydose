/**
 * Basic DSA Problems - Pascal's Triangle
 * Generate first numRows rows of Pascal's triangle
 */
import java.util.*;

public class basic_dsa_one_hundred_nineteen {

    // Problem: Given numRows, return the first numRows of Pascal's triangle.
    // In Pascal's triangle each number is the sum of the two numbers directly above it.

    /**
     * Build each row from the previous: row[i] = prev[i-1] + prev[i], with 1s at ends.
     * Time O(numRows^2), Space O(1) excluding result
     */
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows <= 0) return result;
        result.add(Arrays.asList(1));
        for (int r = 1; r < numRows; r++) {
            List<Integer> prev = result.get(r - 1);
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for (int i = 1; i < r; i++) {
                row.add(prev.get(i - 1) + prev.get(i));
            }
            row.add(1);
            result.add(row);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Pascal's Triangle");
        System.out.println("=".repeat(60));

        System.out.println("numRows=5 -> " + generate(5));
        System.out.println("numRows=1 -> " + generate(1));
    }
}
