/**
 * Basic DSA Problems - Reverse Bits
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_sixty {

    // Problem: Reverse bits of a 32-bit unsigned integer
    // Example: 00000010100101000001111010011100 -> 00111001011110000010100101000000
    // In Java, integers are signed; we treat input as unsigned 32-bit

    /**
     * Reverse bits by extracting each bit and building result
     * Time Complexity: O(32) = O(1)
     * Space Complexity: O(1)
     */
    public static int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (n & 1);
            n >>>= 1;  // unsigned right shift
        }
        return result;
    }

    /**
     * Reverse bits using Integer.reverse()
     */
    public static int reverseBitsBuiltin(int n) {
        return Integer.reverse(n);
    }

    /**
     * Get binary string representation (32 bits) for display
     */
    public static String to32BitBinary(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 32; i++) {
            sb.insert(0, (n & 1));
            n >>>= 1;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Bits");
        System.out.println("=".repeat(60));

        // Test 1: 43261596 (00000010100101000001111010011100)
        int n1 = 43261596;
        int r1 = reverseBits(n1);
        System.out.println("Input:  " + n1);
        System.out.println("Output: " + r1 + " (expected 964176192)");

        // Test 2: -3 (all 1s in binary) -> all 1s reversed = all 1s
        int n2 = -3;
        int r2 = reverseBits(n2);
        System.out.println("\nInput: " + n2 + " -> Output: " + r2);

        // Test 3: 0
        int n3 = 0;
        int r3 = reverseBits(n3);
        System.out.println("\nInput: " + n3 + " -> Output: " + r3);

        // Test 4: 1 (00..01 -> 10..00)
        int n4 = 1;
        int r4 = reverseBits(n4);
        System.out.println("\nInput: " + n4 + " -> Output: " + r4 + " (2^31)");

        // Test 5: Compare with built-in
        int n5 = 15;  // 1111
        System.out.println("\nInput: " + n5 + " -> Custom: " + reverseBits(n5) + ", Builtin: " + reverseBitsBuiltin(n5));
    }
}
