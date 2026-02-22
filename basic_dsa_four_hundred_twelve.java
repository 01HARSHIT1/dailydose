/**
 * Basic DSA Problems - Fizz Buzz (LeetCode 412)
 * Replace with "Fizz" (div 3), "Buzz" (div 5), "FizzBuzz" (both)
 */
public class basic_dsa_four_hundred_twelve {

    // Problem: 1 to n. div3->Fizz, div5->Buzz, both->FizzBuzz, else number.

    /**
     * Check divisibility for each i.
     * Time O(n), Space O(1) output
     */
    public static java.util.List<String> fizzBuzz(int n) {
        java.util.List<String> out = new java.util.ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) out.add("FizzBuzz");
            else if (i % 3 == 0) out.add("Fizz");
            else if (i % 5 == 0) out.add("Buzz");
            else out.add(String.valueOf(i));
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Fizz Buzz");
        System.out.println("=".repeat(60));

        System.out.println("n=5 -> " + fizzBuzz(5));
        System.out.println("n=15 -> " + fizzBuzz(15));
    }
}
