/**
 * Basic DSA Problems - One Fundamental Cycle Detection Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_three {

    // Problem 1: Happy Number
    // A number is happy if, by repeatedly replacing the number with the sum of the squares of its
    // digits, you eventually reach 1. If you loop forever without reaching 1, it is not happy.
    //
    // Example:
    // n = 19 -> true (19 -> 82 -> 68 -> 100 -> 1)
    // n = 2  -> false (enters a cycle that never hits 1)

    private static int sumOfSquaredDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    /**
     * Floyd's cycle detection on the sequence defined by sum of squared digits
     * Time Complexity: O(log n) per step; terminates quickly in practice
     * Space Complexity: O(1)
     */
    public static Boolean isHappy(int n) {
        if (n <= 0) {
            return null;
        }

        int slow = n;
        int fast = n;

        do {
            slow = sumOfSquaredDigits(slow);
            fast = sumOfSquaredDigits(sumOfSquaredDigits(fast));
        } while (fast != 1 && slow != fast);

        return fast == 1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Happy Number");
        System.out.println("=".repeat(60));

        System.out.println("n = 19 -> " + isHappy(19));
        System.out.println("n = 7  -> " + isHappy(7));
        System.out.println("n = 2  -> " + isHappy(2));
        System.out.println("n = 1  -> " + isHappy(1));
        System.out.println("n = 0  -> " + isHappy(0));
        System.out.println("n = -5 -> " + isHappy(-5));
    }
}
