/**
 * Basic DSA Problems - Sparse Number
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_sixty_one {

    // Problem: Check if a Number is Sparse
    // A sparse number has no two consecutive 1s in its binary representation.
    // Example: 5 (101) is sparse; 6 (110) is not - has consecutive 1s at position 1,2
    // 2 (10), 5 (101), 9 (1001) are sparse. 3 (11), 6 (110), 7 (111) are not.

    /**
     * Check if n is sparse: no two consecutive 1s
     * n & (n >> 1) == 0 means no consecutive 1s
     * Time Complexity: O(1)
     */
    public static boolean isSparse(int n) {
        return (n & (n >> 1)) == 0;
    }

    /**
     * Find next sparse number >= n
     */
    public static int nextSparseNumber(int n) {
        while (!isSparse(n)) n++;
        return n;
    }

    /**
     * Find sparse numbers in a range
     */
    public static java.util.ArrayList<Integer> getSparseNumbersInRange(int start, int end) {
        java.util.ArrayList<Integer> result = new java.util.ArrayList<>();
        for (int i = start; i <= end; i++) {
            if (isSparse(i)) result.add(i);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Check if a Number is Sparse");
        System.out.println("=".repeat(60));

        // Test 1: 5 (101) - sparse
        int n1 = 5;
        System.out.println("Number: " + n1 + " (" + Integer.toBinaryString(n1) + ") -> Is Sparse: " + isSparse(n1));

        // Test 2: 6 (110) - not sparse
        int n2 = 6;
        System.out.println("\nNumber: " + n2 + " (" + Integer.toBinaryString(n2) + ") -> Is Sparse: " + isSparse(n2));

        // Test 3: 3 (11) - not sparse
        int n3 = 3;
        System.out.println("\nNumber: " + n3 + " (" + Integer.toBinaryString(n3) + ") -> Is Sparse: " + isSparse(n3));

        // Test 4: 9 (1001) - sparse
        int n4 = 9;
        System.out.println("\nNumber: " + n4 + " (" + Integer.toBinaryString(n4) + ") -> Is Sparse: " + isSparse(n4));

        // Test 5: Next sparse after 6
        int n5 = 6;
        int next = nextSparseNumber(n5);
        System.out.println("\nNext sparse number after " + n5 + ": " + next);

        // Test 6: Sparse numbers in range
        java.util.ArrayList<Integer> sparse = getSparseNumbersInRange(1, 20);
        System.out.println("\nSparse numbers in [1, 20]: " + sparse);
    }
}
