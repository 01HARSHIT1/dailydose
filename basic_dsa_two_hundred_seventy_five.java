/**
 * Basic DSA Problems - Happy Number
 * Check if number reaches 1 when repeatedly summing squares of digits
 */
public class basic_dsa_two_hundred_seventy_five {

    // Problem: Replace n with sum of squares of its digits. Repeat. Return true if reaches 1.
    // Cycle detection: use slow/fast or HashSet.

    /**
     * Floyd cycle detection: slow and fast pointers. If fast reaches 1, happy.
     * Time O(log n), Space O(1)
     */
    public static boolean isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1) return true;
        } while (slow != fast);
        return false;
    }

    static int next(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Happy Number");
        System.out.println("=".repeat(60));

        System.out.println("19 -> " + isHappy(19));
        System.out.println("2 -> " + isHappy(2));
    }
}
