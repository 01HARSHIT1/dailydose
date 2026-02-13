/**
 * Basic DSA Problems - Fizz Buzz
 * Replace numbers divisible by 3/5/15 with Fizz/Buzz/FizzBuzz
 */
public class basic_dsa_two_hundred_forty_one {

    // Problem: For 1 to n, return: "FizzBuzz" if divisible by 3 and 5,
    // "Fizz" if by 3, "Buzz" if by 5, else the number as string.

    /**
     * Check divisibility in order: 15, 3, 5.
     * Time O(n), Space O(1) excluding output
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

        System.out.println("3 -> " + fizzBuzz(3));
        System.out.println("5 -> " + fizzBuzz(5));
        System.out.println("15 -> " + fizzBuzz(15));
    }
}
