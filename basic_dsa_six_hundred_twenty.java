/**
 * Basic DSA Problems - One Fundamental Bit DP Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty {

    // Problem 1: Counting Bits
    // For each i in [0, n], count how many 1-bits in the binary form of i.

    /**
     * ans[i] = ans[i >> 1] + (i & 1) — reuse half the bits of i/2 plus the lowest bit
     * Time Complexity: O(n)
     * Space Complexity: O(n) for output (excluding input)
     */
    public static int[] countBits(int n) {
        if (n < 0) {
            return null;
        }

        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }

    private static String arrToString(int[] a) {
        if (a == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(a[i]);
        }
        return sb.append("]").toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Counting Bits");
        System.out.println("=".repeat(60));

        System.out.println("n=5 -> " + arrToString(countBits(5)));
        System.out.println("n=0 -> " + arrToString(countBits(0)));
        System.out.println("n=2 -> " + arrToString(countBits(2)));
        System.out.println("n=-1 -> " + arrToString(countBits(-1)));
    }
}
