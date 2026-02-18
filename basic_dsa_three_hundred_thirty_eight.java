/**
 * Basic DSA Problems - Counting Bits (LeetCode 338)
 * Return array where ans[i] = count of 1s in binary of i
 */
public class basic_dsa_three_hundred_thirty_eight {

    // Problem: Integer n. Return ans[0..n] where ans[i] = popcount(i).

    /**
     * DP: ans[i] = ans[i >> 1] + (i & 1). Drop LSB, add it back.
     * Time O(n), Space O(1) output
     */
    public static int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i >> 1] + (i & 1);
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Counting Bits");
        System.out.println("=".repeat(60));

        System.out.println("n=2 -> " + java.util.Arrays.toString(countBits(2)));
        System.out.println("n=5 -> " + java.util.Arrays.toString(countBits(5)));
    }
}
