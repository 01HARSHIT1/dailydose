/**
 * Basic DSA Problems - Elimination Game (LeetCode 390)
 * Alternate left-to-right and right-to-left elimination, last remaining
 */
public class basic_dsa_three_hundred_ninety {

    // Problem: [1..n]. Left→right remove odd indices, then right→left, repeat. Return last.

    /**
     * Track head; when going left, head steps. When going right, head steps if count odd.
     * Time O(log n), Space O(1)
     */
    public static int lastRemaining(int n) {
        int head = 1, step = 1;
        boolean left = true;
        while (n > 1) {
            if (left || n % 2 == 1) head += step;
            n /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Elimination Game");
        System.out.println("=".repeat(60));

        System.out.println("n=9 -> " + lastRemaining(9));
        System.out.println("n=1 -> " + lastRemaining(1));
    }
}
