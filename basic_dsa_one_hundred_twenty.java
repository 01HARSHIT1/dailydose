/**
 * Basic DSA Problems - Fibonacci Number
 * Compute nth Fibonacci number (F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2))
 */
public class basic_dsa_one_hundred_twenty {

    // Problem: Given n, return F(n) where F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2).

    /**
     * Iterative: keep two variables for F(i-1) and F(i-2), advance up to n.
     * Time O(n), Space O(1)
     */
    public static int fib(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }
        return b;
    }

    /**
     * Recursive (for reference; exponential time).
     */
    public static int fibRecursive(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Fibonacci Number");
        System.out.println("=".repeat(60));

        System.out.println("n=2 -> " + fib(2));
        System.out.println("n=3 -> " + fib(3));
        System.out.println("n=4 -> " + fib(4));
    }
}
