/**
 * Basic DSA Problems - Perfect Number
 * Check if a number equals the sum of its proper divisors
 */
public class basic_dsa_two_hundred_fifty_five {

    // Problem: A perfect number = sum of its proper positive divisors (excluding itself).
    // Example: 28 = 1 + 2 + 4 + 7 + 14. Return true if num is perfect.

    /**
     * Sum divisors from 1 to sqrt(num). Include both i and num/i when i divides num.
     * Time O(sqrt n), Space O(1)
     */
    public static boolean checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) sum += num / i;
            }
        }
        return sum == num;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Perfect Number");
        System.out.println("=".repeat(60));

        System.out.println("28 -> " + checkPerfectNumber(28));
        System.out.println("7 -> " + checkPerfectNumber(7));
        System.out.println("6 -> " + checkPerfectNumber(6));
    }
}
