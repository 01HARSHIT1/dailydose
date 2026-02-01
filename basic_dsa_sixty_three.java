/**
 * Basic DSA Problems - Find Position of Only Set Bit
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_sixty_three {

    // Problem: Find the position of the only set bit in a number
    // A number has exactly one set bit iff it is a power of 2.
    // Return 1-indexed position. Example: 4 (100) -> position 3; 8 (1000) -> position 4
    // Return -1 if 0 or more than one set bit

    /**
     * Find position using log base 2: log2(n) + 1
     * Time Complexity: O(1)
     */
    public static int findPositionOfOnlySetBit(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) return -1;
        return (int) (Math.log(n) / Math.log(2)) + 1;
    }

    /**
     * Find position by counting right shifts
     * Time Complexity: O(log n)
     */
    public static int findPositionLoop(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) return -1;
        int pos = 0;
        while (n > 0) {
            pos++;
            n >>= 1;
        }
        return pos;
    }

    /**
     * Check if number has exactly one set bit (is power of 2)
     */
    public static boolean hasOnlyOneSetBit(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find Position of Only Set Bit");
        System.out.println("=".repeat(60));

        // Test 1: 4 (100) -> position 3
        int n1 = 4;
        System.out.println("Number: " + n1 + " (" + Integer.toBinaryString(n1) + ") -> Position: " + findPositionOfOnlySetBit(n1));

        // Test 2: 8 (1000) -> position 4
        int n2 = 8;
        System.out.println("\nNumber: " + n2 + " -> Position: " + findPositionOfOnlySetBit(n2));

        // Test 3: 5 (101) -> -1, has 2 set bits
        int n3 = 5;
        System.out.println("\nNumber: " + n3 + " -> Position: " + findPositionOfOnlySetBit(n3));

        // Test 4: 0 -> -1
        int n4 = 0;
        System.out.println("\nNumber: " + n4 + " -> Position: " + findPositionOfOnlySetBit(n4));

        // Test 5: 1 (1) -> position 1
        int n5 = 1;
        System.out.println("\nNumber: " + n5 + " -> Position: " + findPositionOfOnlySetBit(n5));

        // Test 6: Compare methods
        int n6 = 16;
        System.out.println("\nNumber: " + n6 + " -> Log method: " + findPositionOfOnlySetBit(n6) + ", Loop: " + findPositionLoop(n6));
    }
}
