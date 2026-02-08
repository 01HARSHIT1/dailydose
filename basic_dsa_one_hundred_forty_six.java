/**
 * Basic DSA Problems - Fizz Buzz
 * Replace numbers with Fizz/Buzz for multiples of 3/5
 */
import java.util.ArrayList;
import java.util.List;

public class basic_dsa_one_hundred_forty_six {

    // Problem: For numbers 1 to n, return list: "Fizz" if divisible by 3, "Buzz" if by 5,
    // "FizzBuzz" if by both, else the number as string.
    // Example: n=15 -> ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

    /**
     * Time O(n), Space O(1) excluding output
     */
    public static List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) result.add("FizzBuzz");
            else if (i % 3 == 0) result.add("Fizz");
            else if (i % 5 == 0) result.add("Buzz");
            else result.add(String.valueOf(i));
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Fizz Buzz");
        System.out.println("=".repeat(60));

        System.out.println("n=5 -> " + fizzBuzz(5));
        System.out.println("n=15 -> " + fizzBuzz(15));
        System.out.println("n=3 -> " + fizzBuzz(3));
    }
}
