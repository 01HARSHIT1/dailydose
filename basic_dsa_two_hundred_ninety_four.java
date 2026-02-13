/**
 * Basic DSA Problems - Pascal's Triangle II
 * Return k-th row of Pascal's triangle (0-indexed)
 */
public class basic_dsa_two_hundred_ninety_four {

    // Problem: Return rowIndex-th row of Pascal's triangle. Row 0 = [1].
    // O(rowIndex) extra space.

    /**
     * Build row by row. Each row: [1] + [prev[i]+prev[i+1]] + [1].
     * Or use formula: C(n,k) = C(n,k-1) * (n-k+1)/k
     * Time O(rowIndex), Space O(rowIndex)
     */
    public static java.util.List<Integer> getRow(int rowIndex) {
        java.util.List<Integer> row = new java.util.ArrayList<>();
        row.add(1);
        for (int i = 1; i <= rowIndex; i++) {
            row.add(0);
            for (int j = i; j > 0; j--)
                row.set(j, row.get(j) + row.get(j - 1));
        }
        return row;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Pascal's Triangle II");
        System.out.println("=".repeat(60));

        System.out.println("rowIndex=3 -> " + getRow(3));
        System.out.println("rowIndex=0 -> " + getRow(0));
    }
}
