/**
 * Basic DSA Problems - One Fundamental Floyd Cycle Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_one {

    // Problem 1: Happy Number
    // Replace n by sum of squares of its digits repeatedly. If 1 is reached, n is happy;
    // otherwise the sequence loops without hitting 1.

    /**
     * Floyd's cycle: slow one step, fast two steps on f(n) = sum of digit squares
     * Time Complexity: O(log n) per step, finitely many steps for 32-bit n
     * Space Complexity: O(1)
     */
    public static Boolean isHappy(int n) {
        if (n < 1) {
            return null;
        }

        int slow = n;
        int fast = nextSumOfSquares(n);

        while (fast != 1 && slow != fast) {
            slow = nextSumOfSquares(slow);
            fast = nextSumOfSquares(nextSumOfSquares(fast));
        }

        return fast == 1;
    }

    private static int nextSumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Happy Number");
        System.out.println("=".repeat(60));

        System.out.println("19 -> " + isHappy(19));
        System.out.println("2 -> " + isHappy(2));
        System.out.println("1 -> " + isHappy(1));
        System.out.println("7 -> " + isHappy(7));
        System.out.println("0 -> " + isHappy(0));
    }
}
