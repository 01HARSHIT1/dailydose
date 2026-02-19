/**
 * Basic DSA Problems - Count Numbers with Unique Digits (LeetCode 357)
 * Count numbers in [0, 10^n) with all distinct digits
 */
public class basic_dsa_three_hundred_fifty_seven {

    // Problem: n >= 0. Return count of x in [0, 10^n) with unique digits.

    /**
     * For length k: 9 * 9 * 8 * ... * (11-k). Sum for k=1..n (or min(n,10)).
     * Time O(1), Space O(1)
     */
    public static int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 1;
        for (int k = 1; k <= Math.min(n, 10); k++) {
            int prod = 9;
            for (int i = 1; i < k; i++) prod *= (10 - i);
            sum += prod;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Count Numbers with Unique Digits");
        System.out.println("=".repeat(60));

        System.out.println("n=2 -> " + countNumbersWithUniqueDigits(2));
        System.out.println("n=0 -> " + countNumbersWithUniqueDigits(0));
    }
}
