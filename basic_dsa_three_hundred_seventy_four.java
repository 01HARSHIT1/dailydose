/**
 * Basic DSA Problems - Guess Number Higher or Lower (LeetCode 374)
 * Binary search to guess pick in [1, n]; -1=high, 1=low, 0=correct
 */
public class basic_dsa_three_hundred_seventy_four {

    // Problem: guess(n) returns -1(high), 1(low), 0(correct). Find pick in [1,n].

    static int pick = 6;  // simulated pick for testing

    static int guess(int n) {
        return Integer.compare(pick, n);
    }

    /**
     * Binary search. guess(mid): 0=done, -1=go left, 1=go right.
     * Time O(log n), Space O(1)
     */
    public static int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int g = guess(mid);
            if (g == 0) return mid;
            if (g == -1) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Guess Number Higher or Lower");
        System.out.println("=".repeat(60));

        pick = 6;
        System.out.println("n=10, pick=6 -> " + guessNumber(10));
        pick = 1;
        System.out.println("n=1, pick=1 -> " + guessNumber(1));
    }
}
